// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static int mem_list_flag = 0;

void *malloc(size_t size)
{
	if (!mem_list_flag) {
		mem_list_init();
		mem_list_flag = 1;
	}
	if (size == 0) {
		return NULL;
	}

	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (block == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}

	if (mem_list_add(block, size) < 0) {
		munmap(block, size);
		errno = ENOMEM;
		return NULL;
	}

	return block;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size) {
		errno = ENOMEM;
		return NULL;
	}

	return malloc(total);
}

void free(void *ptr)
{
	if (!mem_list_flag) {
		mem_list_init();
		mem_list_flag = 1;
	}

	if (ptr == NULL) {
		return;
	}

	struct mem_list *item = mem_list_find(ptr);

	if (item == NULL) {
		return;
	}

	size_t len = item->len;
	mem_list_del(ptr);
	munmap(ptr, len);
}

void *realloc(void *ptr, size_t size)
{
	if (!mem_list_flag) {
		mem_list_init();
		mem_list_flag = 1;
	}

	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);

	if (item == NULL) {
		errno = EINVAL;
		return NULL;
	}
	size_t old_len = item->len;

	void *new_block = malloc(size);
	if (new_block == NULL) {
		return NULL;
	}
	size_t cp_size = 0;
	if (old_len < size) {
		cp_size = old_len;
	} else {
		cp_size = size;
	}
	memcpy(new_block, ptr, cp_size);

	free(ptr);
	return new_block;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size) {
		errno = ENOMEM;
		return NULL;
	}

	return realloc(ptr, total);
}

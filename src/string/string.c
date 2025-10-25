// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *dest_head = destination;
	
	while (*source != '\0') {
		*destination = *source;
		source++;
		destination++;
	}

	*destination = '\0';

	return dest_head;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    char *dest_head = destination;
	while (len > 0 && *source != '\0') {
		*destination = *source;
		destination++;
		source++;
		len--;
	}

	// padding
	while (len > 0) {
		*destination++ = '\0';
		len--;
	}
	return dest_head;
}

char *strcat(char *destination, const char *source)
{
	char *dest_head = destination;
	while (*destination != '\0') {
		destination++;
	}
	while (1) {
		char tmp = *source;
		*destination = tmp;
		source++;
		destination++;

		if (tmp == '\0') {
			break;
		}
    }
	return dest_head;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *dest_head = destination;

	while (*destination != '\0') {
		destination++;
	}

	while (len > 0 && *source != '\0') {
		*destination = *source;
		source++;
		destination++;

		len--;
	}
	// appends at most len bytes from source and then appends exactly one null terminator
	*destination = '\0';
	return dest_head;
}

int strcmp(const char *str1, const char *str2)
{
	while (1) {
		if (*str1 == '\0') {
			break;
		}
		if (*str1 != *str2) {
			break;
		}
		str1++;
		str2++;
	}
	return (unsigned)*str1 - (unsigned)*str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}

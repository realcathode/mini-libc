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

	return (char *)dest_head;
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
	return (char *)dest_head;
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
	return (char *)dest_head;
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
	return (char *)dest_head;
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
	while (len > 0) {
		if (*str1 == '\0') {
			return 0;
		}
		if (*str1 != *str2) {
			return (unsigned)*str1 - (unsigned)*str2;
		}
		str1++;
		str2++;
		len--;
	}
	return 0;
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
	while (1) {
		if (*str == '\0') {
			return NULL;
		}
		if (*str == (char)c) {
 			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *ret = NULL;
	while (1) {
		if (*str == '\0') {
			break;
		}
		if (*str == (char)c) {
			ret = (char *)str;
		}
		str++;
	}
	return (char *)ret;
}

char *strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
		return (char *)haystack;
	}
	while (*haystack != '\0') {
		char *h_ptr = (char *)haystack;
		char *n_ptr = (char *)needle;

		while (1) {
			if (*n_ptr == '\0') {
				return (char *)haystack;
			}
			if (*h_ptr == '\0') {
				break;
			}
			if (*h_ptr != *n_ptr) {
				break;
			}
			h_ptr++;
			n_ptr++;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last_match = NULL;
	char *current_match = NULL;
	char *curr_haystack = (char *)haystack;

	size_t n_len = strlen(needle);

	if (n_len == 0) {
		return (char *)(haystack + strlen(haystack));
	}

	while (1) {
		current_match = strstr(curr_haystack, needle);

		if (current_match == NULL) {
			break;
		} else {
			last_match = current_match;

			curr_haystack = current_match + 1;
		}
	}

	return last_match;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_ptr = destination;
	char *src_ptr = (char *)source;

	void *dest_head = destination;

	while (num > 0) {
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		num--;
	}

	return dest_head;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_ptr = destination;
	char *src_ptr = (char *)source;

	void *dest_head = destination;

	if (num == 0) {
		return dest_head;
	}
	if (destination == source) {
		return dest_head;
	}

	if (dest_ptr > src_ptr) {
		dest_ptr += num;
		src_ptr += num;
		while (num > 0) {
			--dest_ptr;
			--src_ptr;
			*dest_ptr = *src_ptr;
			num--;
		}
	} else {
		while (num > 0) {
			*dest_ptr = *src_ptr;
			dest_ptr++;
			src_ptr++;
			num--;
		}
	}

	return dest_head;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;

	while (num > 0) {
		if (*p1 != *p2) {
			return (unsigned)*p1 - (unsigned)*p2;
		}
		p1++;
		p2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	void *src_head = source;
	char *src_ptr = source;

	char v = value;

	while (num > 0) {
		*src_ptr = v;
		src_ptr++;
		num--;
	}

	return src_head;
}

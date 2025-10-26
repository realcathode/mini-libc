#include <stdio.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <unistd.h>
#include <internal/syscall.h>

int puts(const char *s)
{
    if (s == NULL)
        return -1;

    long len = 0;
    while (s[len])
        len++;

    long ret = syscall(__NR_write, 1, s, len);
    if (ret < 0)
        return -1;

    ret = syscall(__NR_write, 1, "\n", 1);
    if (ret < 0)
        return -1;

    return 0;
}
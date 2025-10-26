#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec duration;
    struct timespec rem;

    duration.tv_sec = (time_t)seconds;
    duration.tv_nsec = 0;

    int ret = nanosleep(&duration, &rem);

    return ret;
}

#ifndef ASSIGNMENT_MINI_LIBC_TIME_H
#define ASSIGNMENT_MINI_LIBC_TIME_H

#ifndef __time_t_defined
#define __time_t_defined
typedef long time_t;
#endif

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

int nanosleep(const struct timespec *duration, struct timespec *rem);
unsigned int sleep(unsigned int seconds);


#endif //ASSIGNMENT_MINI_LIBC_TIME_H

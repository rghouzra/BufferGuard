#ifndef BUFFER_GUARD_H
# define BUFFER_GUARD_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>
#include <errno.h>
void check_buffer_overflow(void* buffer, size_t buffer_size);
int invalid_addr(void *ptr, size_t len);
#endif
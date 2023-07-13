#ifndef BUFFER_GUARD_H
# define BUFFER_GUARD_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void check_buffer_overflow(void* buffer, size_t buffer_size);
#endif
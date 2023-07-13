#include "buffer_guard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void throw_error(char *exception)
{
	write(2, "Error: ", strlen("Error: "));
	write(2, exception, strlen(exception));
	exit(1);
}

void check_buffer_overflow(void* buffer, size_t buffer_size) {
    size_t i;
    char* buffer_end;

     if (buffer == 0x0)
	return ;
     buffer_end = (char*) buffer + buffer_size;
    memset(buffer, 0xA, buffer_size);
    *((char*) buffer_end - 1) = 0x00;
    *((char*) buffer_end) = 0xF;
    for (i = 0; i < buffer_size; i++) {
        if (*((char*) buffer + i) != 0xA) {
		throw_error("buffer overflow detected\n");
        }
    }
}

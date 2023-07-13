#include "buffer_guard.h"

int invalid_addr(void *ptr, size_t len){
	int is_mapped;
	int fd[2];

	is_mapped = 0;
	if(!ptr)
		return -1;
	pipe(fd);
	if(write(fd[1], ptr, len) < 0){
		is_mapped = ((errno == EFAULT) * -1);
	}
	close(fd[1]);
	close(fd[0]);
	return is_mapped;
}

#include "buffer_guard.h"

sigjmp_buf jump_buffer;

void sigsegv_handler(int signo) {
	(void)signo;
	siglongjmp(jump_buffer, 1);
}

int isPointerValid(const void* ptr) {
	if (ptr == NULL) {
		return 0;     }

	if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) {
		return 0;
	}

	if (sigsetjmp(jump_buffer, 1) == 0) {
		volatile char value = *((volatile char*)ptr);
		(void)value;
	} else {
		signal(SIGSEGV, SIG_DFL);
		return 0;
	}
	signal(SIGSEGV, SIG_DFL);

	return 1;
}



NAME = libbuffguard.a

SRCS = buffer_guard.c invalid_addr.c
INCS = buffer_guard.h
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra

all:$(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ -o $<
%.o : %.c
	gcc -c $(FLAGS) $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
.PHONY: all re clean fclean
.DEFAULT: all

CC := clang
LD := clang

CFLAGS := -g3 -Wall -Wextra -Werror -Iinc -fno-omit-frame-pointer -O1 # -fsanitize=thread
LDFLAGS := -g3 -pthread -fno-omit-frame-pointer -O1 # -fsanitize=thread

NAME := philo

SRCS := src/main.c \
		src/conf.c \
		src/corruption.c \
		src/philo.c \
		src/ph_allocator.c \
		src/philo_access.c \
		src/philo_fork.c \
		src/utils.c \

INCS :=

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS) $(INCS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

re: fclean all

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

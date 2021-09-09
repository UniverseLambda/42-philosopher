.PHONY: all re clean fclean
.DEFAULT: all

CC := clang
LD := clang

CFLAGS := -g3 -pthread -Wall -Wextra -Werror -Iinc -fno-omit-frame-pointer # -fsanitize=undefined -fsanitize=thread -fstack-protector-all
LDFLAGS := -g3 -pthread -fno-omit-frame-pointer # -fsanitize=undefined -fsanitize=thread -fstack-protector-all

NAME := philo

SRCS := src/main.c \
		src/conf.c \
		src/corruption.c \
		src/philo.c \
		src/ph_allocator.c \
		src/philo_access.c \
		src/philo_fork.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putnbr_fd.c \
		src/utils.c \

INCS :=	inc/bool.h \
		inc/conf.h \
		inc/corruption.h \
		inc/ph_allocator.h \
		inc/philo.h \
		inc/philo_fork.h \
		inc/state.h \
		inc/utils.h \

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

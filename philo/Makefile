.PHONY: all re clean fclean
.DEFAULT: all

CC := clang
LD := clang

COMMONFLAGS := -g3 -pthread

CFLAGS := $(COMMONFLAGS) -Wall -Wextra -Werror -Iinc # -fsanitize=undefined -fsanitize=thread -fstack-protector-all
LDFLAGS :=  # -fsanitize=undefined -fsanitize=thread -fstack-protector-all

NAME := philo

SRCS :=	src/conf.c \
		src/corruption.c \
		src/ft_putchar_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c \
		src/main.c \
		src/ph_allocator.c \
		src/philo.c \
		src/philo_access.c \
		src/philo_fork.c \
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

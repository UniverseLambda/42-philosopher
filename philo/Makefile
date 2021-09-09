.PHONY: all re clean fclean
.DEFAULT: all

CC := clang
LD := clang

COMMONFLAGS := -g3 -pthread -Wall -Wextra -Werror

CFLAGS := $(COMMONFLAGS) -Iinc
LDFLAGS := $(COMMONFLAGS)

NAME := philo

SRCS :=	src/conf.c \
		src/corruption.c \
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

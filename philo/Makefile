.PHONY: all re clean fclean
.DEFAULT: all

CC := gcc
LD := gcc

CFLAGS := -g -Wall -Wextra -Werror -Iinc -fsanitize=address
LDFLAGS := -g -fsanitize=address -pthread

NAME := philo

SRCS := src/main.c \
		src/conf.c \
		src/philo.c \
		src/ph_allocator.c \
		src/util.c \

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

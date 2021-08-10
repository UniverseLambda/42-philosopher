.PHONY: all re clean fclean

CC := gcc
LD := gcc

CFLAGS := -g -Wall -Wextra -Werror -Iinc
LDFLAGS := -g

NAME := philo

SRCS := src/main.c \
		src/conf.c \

INCS :=

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS) $(INCS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

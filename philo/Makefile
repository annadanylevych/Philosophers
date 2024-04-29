SRCS = main.c parsing.c utils_parsing.c inition.c dinner.c eatsleepthink.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

NAME = philo

HEADER = philosophers.h

all: $(NAME)

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)  

re: fclean $(NAME)
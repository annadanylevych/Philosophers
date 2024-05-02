SRCS = main.c parsing.c utils_parsing.c init.c dinner.c deadly_functions.c \
	eatsleepthink.c time_functions.c

TMP = .tmp/

OBJS = $(addprefix $(TMP), $(SRCS:.c=.o))

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

NAME = philo

HEADER = philosophers.h

all: $(TMP) $(NAME)

$(TMP):
	@mkdir -p $(TMP)

$(TMP)%.o:%.c	$(HEADER) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(TMP) 

fclean: clean
	$(RM) $(NAME)  

re: fclean $(NAME)
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = convert_tab.c lst_sort.c push_swap_function1.c push_swap_utils.c error.c

OBJECTS = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean  re
NAME = push_swap

NAMEBONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = convert_tab.c lst_sort.c push_swap_function1.c push_swap_function2.c push_swap_function3.c \
		push_swap_utils.c push_swap_utils2.c push_swap_utils3.c error.c

SRCSBONUS = checker_fonction1.c checker_fonction2.c checker_fonction3.c checker_utils.c checker.c \
		convert_tab_bonus.c error_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(SRCS:.c=.o) 

OBJECTSBONUS = $(SRCSBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(OBJECTSBONUS)

fclean:	clean
	rm -f $(NAME) $(NAMEBONUS)

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(OBJECTSBONUS)
	$(CC) $(CFLAGS) -o $(NAMEBONUS) $(OBJECTSBONUS)

re: fclean all

.PHONY:	all clean fclean bonus re
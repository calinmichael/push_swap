NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = push_swap.c \
	   operations1.c \
	   operations2.c \
	   utils_lst1.c \
	   utils1.c \
	   validate.c \
	   turk_sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

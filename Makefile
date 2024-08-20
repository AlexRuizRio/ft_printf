CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

AR = ar rc

RM = rm -f

SRCS = ft_print_char.c ft_print_hexa.c ft_print_int.c\
		ft_print_pointer.c ft_print_str.c ft_print_unsigned.c\
		ft_printf.c

OBJS = $($SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR)$@$^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



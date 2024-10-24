NAME = libft.a
CC = cc
SRCS = ft_printf/ft_printf.c ft_printf/print_char.c ft_printf/print_hex.c ft_printf/print_int.c ft_printf/ft_putchar_fd.c ft_printf/ft_putstr_fd.c ft_printf/ft_strlen.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@make -j4 -s -C MacroLibX/ all
	@echo "\033[1;32m -= Library compiled =-"

$(NAME): $(OBJS)
	@ar -crs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@make -s -C MacroLibX/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C MacroLibX/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re

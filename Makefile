NAME = fractol
CC = cc
SRCS = srcs/main.c \
	srcs/starter.c \
	srcs/colors.c \
	srcs/fractal_calc.c \
	srcs/hooks.c \
	srcs/key_pressed.c \
	srcs/movement.c \
	srcs/utils.c \
	srcs/window.c \
	srcs/palette.c
	
INCLUDES = includes/libft.a includes/MacroLibX/libmlx.so
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

ifdef W_WIDTH
 FLAGS += -D W_WIDTH=$(W_WIDTH)
endif

ifdef W_HEIGHT
 FLAGS += -D W_HEIGHT=$(W_HEIGHT)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C includes/ all
	@$(CC) $(FLAGS) $^ $(INCLUDES) -o $(NAME) -lSDL2 -lm
	@echo "\033[1;32m -= Sources compiled =-"
	

%.o: %.c
	@$(CC) $(FLAGS) $< -c -o $@

clean:
	@make -s -C includes/ clean
	@rm -f $(OBJS)
	@echo "\033[1;31m -= Sources removed =-"
	@echo "\033[1;31m -= Includes removed =-"

fclean: clean
	@make -s -C includes/ fclean
	@rm -f $(NAME)
	@echo "\033[1;31m -= Executable removed =-"
	@echo "\033[1;31m -= Library removed =-"

re: fclean all

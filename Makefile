NAME = fractol

SRC =	fractol.c meth.c\
		src/colors.c src/zoom.c src/captain_hook.c src/up_down_left_right.c\
		src/utils.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBS = ./MLX42/build/libmlx42.a -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib"

LIBFT =	./includes/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS) $(LIBFT)

$(LIBFT):
			@cd includes/libft && make
			@cd includes/libft && make clean

%.o: %.c fractol.h
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@cd	includes/libft && make fclean

re: fclean all

.PHONY: all clean fclean re

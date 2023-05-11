NAME = fractol

SRC =	fractol.c meth.c\
		src/colors.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBS = ./MLX42/build/libmlx42.a -lglfw -L "/Users/mreidenb/homebrew/opt/glfw/lib"

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c fractol.h
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

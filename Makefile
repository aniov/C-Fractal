# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoina <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 10:05:52 by mvoina            #+#    #+#              #
#    Updated: 2015/12/10 23:08:59 by mvoina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol_source/fractol.c\
      fractol_source/read_input.c\
      fractol_source/input_hook.c\
      fractol_source/menu_info.c\
      fractol_source/fractol_sets.c\
      fractol_source/hooks.c\

OBJ = fractol.o\
      read_input.o\
      input_hook.o\
      menu_info.o\
      fractol_sets.o\
      hooks.o\

FLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(SRC) $(FLAGS)
	@gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

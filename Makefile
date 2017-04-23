#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 18:06:03 by tprysiaz          #+#    #+#              #
#    Updated: 2017/03/31 21:36:20 by tprysiaz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FLAGS = -Wall -Werror -Wextra -O3
MLX_FLAGS = -lmlx -framework OpenGl -framework AppKit
SRC = fdf.c split.c get_next_line.c drawimg.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) libft/libft.a
%.o: %.c
	clang -I ./libft/ -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJ) $(NAME)

re: fclean all

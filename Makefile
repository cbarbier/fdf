# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 14:05:46 by jgengo            #+#    #+#              #
#    Updated: 2016/12/01 14:26:24 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -lmlx -framework OpenGL -framework AppKit
SRCS			= srcs/main.c \
				  srcs/checkfile.c \
				  srcs/str_to_int_tab.c \
				  srcs/draw.c \
				  srcs/mlx.c \
				  srcs/adjust.c

all: $(NAME)

$(NAME): $(LIB) $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)

$(LIB):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 15:30:43 by pivanovi          #+#    #+#              #
#    Updated: 2014/04/21 19:45:22 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = wolf3d

SRC =		tools/ft_putchar.c				\
			tools/ft_putstr.c				\
			tools/ft_putnbr.c				\
			tools/ft_strjoin.c				\
			tools/ft_strlen.c				\
			tools/ft_strsplit.c				\
			tools/ft_atof.c					\
			tools/get_next_line.c			\
			parser/fill_struct.c			\
			parser/free_tab.c				\
			src/mlx_color_image.c			\
			src/setters.c					\
			src/maths.c						\
			src/gere.c						\
			src/keys.c						\
			main.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./includes -I /usr/X11/include
LIBX = -L /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBX)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

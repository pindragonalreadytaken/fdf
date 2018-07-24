# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 12:09:34 by jnaddef           #+#    #+#              #
#    Updated: 2017/11/03 11:26:03 by jnaddef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c \
	   matrix_operations.c \
	   vector_operations.c \
	   draw_line.c \
	   grid_initialization.c \
	   process_key_event.c \
	   fill_pixel.c \
	   calculate_color.c \
	   check_screen.c \
	   print_points.c \
	   clear_points.c \
	   clear_then_exit.c \
	   project_on_screen.c \




OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = libft

.PHONY: all, clean, fclean, re, $(LIB_DIR)

all: $(LIB_DIR) $(NAME)

$(LIB_DIR):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIB_DIR) -lft -I$(LIB_DIR)  -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): fdf.h libft/libft.h

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

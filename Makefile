# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:12:39 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/01/23 01:34:57 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

INCLUDE = include

SRC_DIR = src
SRC_FILES =	push_swap		\
			check_input		\
			init_stack		\
			stack_utilities	\
			quicksort		\
			sort_big		\
			sort_small		\
			push_ops		\
			swap_ops		\
			rotate_ops		\
			rev_rotate_ops

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all :
		mkdir -p $(OBJ_DIR)
		make -C libft
		make $(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

clean :
			rm -rf $(OBJ_DIR) $(NAME)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			make fclean -C $(LIBFT_DIR)

re:			fclean all

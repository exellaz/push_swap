# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:12:39 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/01/19 15:12:04 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

INCLUDE = include

SRC_DIR = src
SRC_FILES =	push_swap		\
			init_stack		\
			sorting			\
			push_ops		\
			swap_ops		\
			rotate_ops		\
			rev_rotate_ops

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT_DIR = libft
LIBFT = libft.a

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR) :
			mkdir -p $(OBJ_DIR)

$(NAME) : 	$(OBJ_DIR) $(OBJ)
			$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_DIR)/$(LIBFT) $(OBJ) -o $(NAME)

all :		$(NAME)
			make libft $(NAME)

libft:
			make -C $(LIBFT_DIR)

clean :
			rm -rf $(OBJ_DIR)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			make fclean -C $(LIBFT_DIR)

re:			fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:12:39 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/02/04 22:11:31 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

INCLUDE = include

SRC_DIR = src
BONUS_DIR = bonus

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
			rev_rotate_ops	\
			free

BONUS_SRC_FILES =	push_swap_checker		\
					check_input				\
					check_instructions		\
					free					\
					init_stack				\
					push_ops				\
					rev_rotate_ops			\
					rotate_ops				\
					stack_utilities			\
					swap_ops

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(BONUS_SRC_FILES)))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all :
		mkdir -p $(OBJ_DIR)
		make -C libft
		make $(NAME)

bonus :
		mkdir -p $(OBJ_DIR)
		make -C libft
		make $(BONUS_NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME):	$(BONUS_OBJ)
				$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

clean :
			rm -rf $(OBJ_DIR) $(NAME)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			rm -rf $(OBJ_DIR) $(BONUS_NAME)
			make fclean -C $(LIBFT_DIR)

re:			fclean all

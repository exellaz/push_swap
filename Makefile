# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:12:39 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/06/12 19:41:11 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

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

BONUS_SRC_FILES =	bonus_checker					\
					bonus_check_input				\
					bonus_check_instructions		\
					bonus_free						\
					bonus_init_stack				\
					bonus_push_ops					\
					bonus_rev_rotate_ops			\
					bonus_rotate_ops				\
					bonus_stack_utilities			\
					bonus_swap_ops

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(BONUS_SRC_FILES)))

OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all :
		@mkdir -p $(OBJ_DIR)
		@make -C libft
		@make $(NAME)

bonus :
		@mkdir -p $(BONUS_OBJ_DIR)
		@make -C libft
		@make $(BONUS_NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c
							@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) :	$(OBJ)
			@printf "$(GREEN)push_swap object files created.$(RESET)\n"
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME) && echo "$(GREEN)push_swap created.$(RESET)"

$(BONUS_NAME):	$(BONUS_OBJ)
				@printf "$(GREEN)checker object files created.$(RESET)\n"
				@$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME) && echo "$(GREEN)checker created.$(RESET)"

clean :
			@rm -rf $(OBJ_DIR) && echo "$(RED)push_swap object files deleted.$(RESET)"
			@rm -rf $(BONUS_OBJ_DIR) && echo "$(RED)checker object files deleted.$(RESET)"
			@make clean -C $(LIBFT_DIR)

fclean:
			@rm -rf $(OBJ_DIR) $(NAME) $(BONUS_OBJ_DIR) $(BONUS_NAME) && echo "$(RED)push_swap deleted.\nchecker deleted.$(RESET)"
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:	clean fclean re all bonus

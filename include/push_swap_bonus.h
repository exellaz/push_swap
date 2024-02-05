/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:37 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 21:40:09 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack	**a;
	t_stack	**b;
	int		size_a;
	int		size_b;
	int		total_size;
}	t_data;

/*Validate Input*/
char	**get_input(int ac, char **av);
int		check_digit(char **av);
int		is_sorted(t_stack **stack);
int		check_dupe(char **av);

/*Stack Functions*/
t_stack	*find_last(t_stack *node);
int		init_stack_a(t_stack **a, char **input, int ac);
void	init_struct(t_data *data, t_stack **a, t_stack **b, int size);
void	append_node(t_stack **stack, int nbr);

/*Reverse Rotate*/
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_data *data);

/*Rotate*/
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_data *data);

/*Swap*/
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_data *data);

/*Push*/
void	push(t_stack **dst, t_stack **src);
void	pa(t_data *data);
void	pb(t_data *data);

/*Free*/
void	free_all(t_data *data);
void	free_stack(t_stack *stack);
void	free_arrays(char **array);

/*Check Instructions*/
void	check_instructions(t_data *data);
int		do_operation(t_data *data, char *op);
#endif

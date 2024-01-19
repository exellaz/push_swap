/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:37 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 22:06:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
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

int		init_stack_a(t_stack **a, int ac, char **av);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_last(t_stack *node);
void printList(const t_stack *head);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_data *data);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_data *data);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_data *data);
void	push(t_stack **dst, t_stack **src);
void	pa(t_data *data);
void	pb(t_data *data);
void	insertion_sort(t_stack **a, t_stack **b);
int	find_stack_size(t_stack *stack);
int	find_smallest(t_stack *stack);
void	pre_sort(t_data *data);
void	quicksort(int *array, int low, int high);
int	partition(int *array, int low, int high);
void	ft_swap(int *a, int *b);
void	stack_to_array(t_stack *stack, int *array);
int binary_search(int *array, int left, int right, int key);
void    partition_in_b(t_data *data, int partition_size, int n, int pb_count);
void	sort_back(t_data *data);
int	can_push(t_data *data, int swap, int *sorted_array);
int	quick_rotate(t_data *data, int *sorted_array);
int	find_pos(t_stack **stack, int target);
void	init_struct(t_data *data, t_stack **a, t_stack **b, int size);
// int	can_push(t_data *data, int swap);



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:37 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/26 17:46:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

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

void	init_stack_a(t_stack **a, char **av);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_last(t_stack *node);
void printList(const t_stack *head);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	rotate(t_stack **stack);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	swap(t_stack **node);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);
void	insertion_sort(t_stack **a, t_stack **b);
int	find_stack_size(t_stack *stack);
int	find_smallest(t_stack *stack);
void	pre_sort(t_data *data);
void	quicksort(int *array, int low, int high);
int	partition(int *array, int low, int high);
void	ft_swap(int *a, int *b);
void	stack_to_array(t_stack *stack, int *array);
int binary_search(int *array, int left, int right, int key);

#endif

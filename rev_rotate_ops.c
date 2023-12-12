/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:55:24 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/12 15:31:45 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	*(stack)->next->prev = last_node;
}

void	rra(t_stack **a, int print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
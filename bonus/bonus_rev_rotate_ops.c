/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:55:24 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 22:30:14 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
}

void	rrr(t_data *data)
{
	rev_rotate(data->a);
	rev_rotate(data->b);
}

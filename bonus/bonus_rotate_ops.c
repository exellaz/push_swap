/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:57:34 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 22:30:22 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
}

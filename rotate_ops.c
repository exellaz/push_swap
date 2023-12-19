/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:57:34 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/19 17:24:30 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		printf("ra\n");
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		printf("rr\n");
}

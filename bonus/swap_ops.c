/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:57:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 22:30:33 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
}

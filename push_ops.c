/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/11 17:33:01 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = 0;
	push_node->prev = 0;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = 0;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, int print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

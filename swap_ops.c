/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:57:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/12 16:25:13 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **node)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*node) || !(*node)->next)
		return ;
	first = *node;
	second = first->next;
	if (second->next)
		second->next->prev = first;z
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*node = second;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}

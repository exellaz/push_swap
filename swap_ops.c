/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:57:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/04 14:59:05 by kkhai-ki         ###   ########.fr       */
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
		second->next->prev = first;
	first->prev = second;
	second->prev = NULL;
	first->next = second->next;
	if (second->next)
        second->next = first->next->prev;
    else
        second->next = first;
	*node = second;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print)
		printf("sa\n");
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print)
		printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		printf("ss\n");
}

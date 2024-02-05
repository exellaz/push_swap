/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/05 16:05:23 by kkhai-ki         ###   ########.fr       */
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
		(*dst)->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_data *data)
{
	push(data->a, data->b);
	data->size_a++;
	data->size_b--;
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push(data->b, data->a);
	data->size_a--;
	data->size_b++;
	ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:12:49 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/23 01:43:36 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max_node(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);

}

void get_three(t_data *data)
{
	t_stack	*min_node;
	int	target;
	int		pos;

	while (data->size_a != 3)
	{
		min_node = find_min_node((*data->a));
		target = min_node->value;
		pos = find_pos((*data->a), target);
		while ((*data->a)->value != target)
		{
			if (pos < data->size_a / 2)
				ra(data->a);
			else
				rra(data->a);
		}
		pb(data);
	}
}

void	sort_small(t_data *data)
{
	if (data->total_size <= 3)
		sort_three(data->a);
	else if (data->total_size <= 15)
	{
		get_three(data);
		sort_three(data->a);
		while (*data->b)
			pa(data);
	}
}

void	do_sort(t_data *data)
{
	if (data->total_size == 2)
		sa(data->a);
	else if (data->total_size <= 15)
		sort_small(data);
	else
		sort_big(data);
}

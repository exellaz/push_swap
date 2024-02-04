/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 13:39:23 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_in_b(t_data *data, int partition_size, int n, int pb_count)
{
	while (data->size_a)
	{
		if ((*data->a)->value < (partition_size * n))
		{
			pb(data);
			if ((*data->b)->value < partition_size * n - (partition_size / 2))
				rb(data->b);
			pb_count++;
		}
		else
			ra(data->a);
		if ((pb_count == partition_size * n)
			&& (partition_size * n < data->total_size))
			n++;
	}
}

int	can_push(t_data *data, int swap, int *sorted_array)
{
	if ((*data->b)->value == sorted_array[data->size_b - 2] && swap == 0)
	{
		pa(data);
		return (1);
	}
	return (0);
}

int	quick_rotate(t_data *data, int *sorted_array)
{
	int	swap;
	int	target;
	int	pos;

	if (!sorted_array)
		return (0);
	swap = 0;
	target = data->size_b - 1;
	pos = find_pos((*data->b), target);
	while ((*data->b)->value != target)
	{
		if (can_push(data, swap, sorted_array) == 0)
		{
			if (pos < data->size_b / 2)
				rb(data->b);
			else
				rrb(data->b);
		}
		else
			swap = 1;
	}
	return (swap);
}

void	sort_back(t_data *data)
{
	int	*sorted_array;

	sorted_array = malloc(sizeof(int) * data->size_b);
	stack_to_array(*data->b, sorted_array);
	quicksort(sorted_array, 0, data->size_b - 1);
	while (data->size_b != 0)
	{
		if (quick_rotate(data, sorted_array))
		{
			pa(data);
			if (data->size_b > 1 && (*data->b)->value < (*data->b)->next->value)
				ss(data);
			else
				sa(data->a);
		}
		else
			pa(data);
	}
	free(sorted_array);
}

void	sort_big(t_data *data)
{
	pre_sort(data);
	partition_in_b(data, (data->total_size / 20) + 30, 1, 0);
	sort_back(data);
}

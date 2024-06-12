/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:05:07 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/12 18:27:06 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

int	partition(int *array, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_value)
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[high]);
	return (i);
}

int	binary_search(int *array, int left, int right, int key)
{
	int	mid;

	mid = 0;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (array[mid] == key)
			return (mid);
		if (array[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	quicksort(int *array, int low, int high)
{
	int	pivot_index;

	if (low >= high)
		return ;
	pivot_index = partition(array, low, high);
	quicksort(array, low, pivot_index - 1);
	quicksort(array, pivot_index + 1, high);
}

void	pre_sort(t_data *data)
{
	int		*temp_array;
	t_stack	*stack;
	int		index;

	stack = *data->a;
	temp_array = malloc(sizeof(int) * data->size_a);
	stack_to_array(stack, temp_array);
	quicksort(temp_array, 0, data->size_a - 1);
	while (stack != NULL)
	{
		index = binary_search(temp_array, 0, data->size_a - 1, stack->value);
		if (index != -1)
			stack->value = index;
		stack = stack->next;
	}
	free(temp_array);
}

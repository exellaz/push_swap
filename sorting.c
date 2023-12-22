/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/22 21:43:33 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	insertion_sort(t_stack **a, t_stack **b)
// {
// 	int		position;
// 	int		stack_size;

// 	while(*a != NULL)
// 	{
// 		position = find_smallest(*a);
// 		stack_size = find_stack_size(*a);
// 		// printf("pos: %d\n", position);
// 		// printf("size: %d\n", stack_size);
// 		if (position < stack_size/2 && position != 0)
// 			while (position-- > 0)
// 				ra(a, 1);
// 		else if (position >= stack_size/2 && position != 0)
// 			while (++position <= stack_size)
// 				rra(a, 1);
// 		pb(b, a, 1);
// 		// printList(*a);
// 	}
// }
int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
			ft_swap(&array[i], &array[j]);
	}
	return (j);
}

void	quicksort(int *array, int low, int high)
{
	int	pivot_index;

	if (low > high)
		return ;
	pivot_index = partition(array, low, high);
	quicksort(array, low, pivot_index - 1);
	quicksort(array, pivot_index + 1, high);
}

int	find_stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	find_smallest(t_stack *stack)
{
	int		position;
	int		smallest_position;
	t_stack	*smallest;

	position = 0;
	smallest_position = 0;
	smallest = stack;
	while (stack != NULL)
	{
		if (stack->value < smallest->value)
		{
			smallest = stack;
			smallest_position = position;
		}
		stack = stack->next;
		position++;
	}
	return (smallest_position);
}

void	pre_sort(t_data *data, int *temp_array)
{
	int	size;
	int	i;
	int	j;

	quicksort(temp_array, 0, data->size_a - 1);
	size = data->size_a;
	i = 0;
	j = 0;
	while (size > 0)
	{

	}
}

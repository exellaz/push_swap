/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:34 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[low];
	i = low + 1;
	j = high;
	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			ft_swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	ft_swap(&array[low], &array[j]);
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

void	pre_sort(t_data *data)
{
	int	*temp_array;
	t_stack *stack;
	int index;

	stack = *data->a;
	temp_array = malloc(sizeof(int) * data->size_a);
	stack_to_array(stack, temp_array);
	quicksort(temp_array, 0, data->size_a - 1);
	while (stack != NULL)
	{
		index = binary_search(temp_array, 0, data->size_a - 1, stack->value);
		if (index != -1)
		{
			stack->value = index;
		}
		stack = stack->next;
	}
	free(temp_array);
}

void	stack_to_array(t_stack *stack, int *array)
{
	int	i;
	t_stack *head;

	i = 0;
	head = stack;
	while (stack != NULL)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	stack = head;
}

int binary_search(int *array, int left, int right, int key)
{
	int mid;

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
		if ((pb_count == partition_size * n) && (partition_size * n < data->total_size))
			n++;
	}
}

void	sort_back(t_data *data)
{
	t_stack	*stack;
	int	*sorted_array;

	stack = (*data->b);
	sorted_array = malloc(sizeof(int) * data->size_b);
	stack_to_array(*data->b, sorted_array);
	quicksort(sorted_array, 0, data->size_b - 1);
	while (data->size_b != 0)
	{
		if (quick_rotate(data, sorted_array))
		{
			pa(data);
			if (data->size_b > 1 && (stack->value < (*data->b)->next->value))
				ss(data);
			else
				sa(data->a);
		}
		else
			pa(data);
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
	int target;
	int	pos;

	swap = 0;
	target = data->size_b - 1;
	pos = find_pos(data->b, target);
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

int	find_pos(t_stack **stack, int target)
{
	int	pos;
	t_stack *head;

	pos = 0;
	head = *stack;
	while ((*stack)->value != target)
	{
		*stack = (*stack)->next;
		pos++;
	}
	*stack = head;
	return (pos);
}

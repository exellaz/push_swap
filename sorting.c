/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/04 15:03:05 by kkhai-ki         ###   ########.fr       */
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
	// printList(*data->a);
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
		// printf("Once\n");
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

void	make_chunks(t_data *data, int chunk_size, int n, int pb_count)
{
	while (data->size_a)
	{
		if ((*data->a)->value < (chunk_size * n))
		{
			pb(data, 1);
			if ((*data->b)->value < chunk_size * n - (chunk_size / 2))
				rb(data->b, 1);
			pb_count++;
		}
		else
			ra(data->a, 1);
		if ((pb_count == chunk_size * n) && (chunk_size * n < data->total_size))
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
	// printf("%d\n", (*data->b)->value);
	quicksort(sorted_array, 0, data->size_b - 1);
	while (data->size_b != 0)
	{
		// printf("test");
		if (quick_rotate(data, sorted_array))
		{
			pa(data, 1);
			// printf("test2");
			if (data->size_b > 1 && (stack->value < (*data->b)->next->value))
				ss(data->a, data->b, 1);
			else
				sa(data->a, 1);
		}
		else
			pa(data, 1);
	}
}

int	can_push(t_data *data, int swap, int *sorted_array)
{
	// printf("value: %d\n", sorted_array[data->size_b - 1]);
	// printf("value2: %d\n", (*data->b)->value);
	if ((*data->b)->value == sorted_array[data->size_b - 2] && swap == 0)
	{
		// printf("size: %d\n", data->size_b - 1);
		// printf("test3");
		pa(data, 1);
		return (1);
	}
	return (0);
}

int	quick_rotate(t_data *data, int *sorted_array)
{
	int	swap;
	int	size;
	int	pos;
	t_stack *head;

	swap = 0;
	pos = 0;
	size = data->size_b;
	head = *data->b;
	while ((*data->b)->value != size - 1)
	{
		*data->b = (*data->b)->next;
		// printf("value: %d", (*data->b)->value);
		// printf("size: %d\n", size);
		pos++;
	}
	*data->b = head;
	while ((*data->b)->value != size - 1)
	{
		if (can_push(data, swap, sorted_array) == 0)
		{
			if (pos < size / 2)
				rb(data->b, 1);
			else
				rrb(data->b, 1);
		}
		else
			swap = 1;
	}
	return (swap);
}

// int	can_push(t_data *data, int swap)
// {
// 	int	*sorted_array;

// 	sorted_array = malloc(sizeof(int) * data->size_b);
// 	stack_to_array(*data->b, sorted_array);
// 	quicksort(sorted_array, 0, data->size_b);
// 	if ((*data->b)->value == sorted_array[data->size_b - 2] && swap == 0)
// 	{
// 		// printf("size: %d\n", data->size_b - 2);
// 		pa(data, 1);
// 		return (1);
// 	}
// 	return (0);
// }

// void	sort_back(t_data *data)
// {
// 	t_stack	*stack;
// 	int	*sorted_array;

// 	stack = *data->b;
// 	sorted_array = malloc(sizeof(int) * data->size_b);
// 	stack_to_array(*data->b, sorted_array);
// 	// printf("%d\n", (*data->b)->value);
// 	quicksort(sorted_array, 0, data->size_b - 1);
// 	while (data->size_b != 0)
// 	{
// 		if (quick_rotate(data, sorted_array))
// 		{
// 			pa(data, 1);
// 			if (data->size_b > 1 && stack->value < stack->next->value)
// 				ss(data->a, data->b, 1);
// 			else
// 				sa(data->a, 1);
// 		}
// 		else
// 			pa(data, 1);
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/26 18:12:37 by kkhai-ki         ###   ########.fr       */
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
	int	i;
	int	*temp_array;
	t_stack *stack;
	int index;

	i = 0;
	stack = *data->a;
	temp_array = malloc(sizeof(int) * data->size_a);
	stack_to_array(stack, temp_array);
	quicksort(temp_array, 0, data->size_a - 1);

    for (int z = 0; z < data->size_a; z++) {
        printf("%d ", temp_array[z]);
    }
    printf("\n");
	i = 0;
	// while (stack != NULL)
	// {
	// 	if (stack->value == temp_array[i])
	// 	{
	// 		stack->value = i;
	// 		i = -1;
	// 	}
	// 	if (i == -1)
	// 		stack = stack->next;
	// 	i++;
	// }

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
	printList(*data->a);
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
		printf("Once\n");
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

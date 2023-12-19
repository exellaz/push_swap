/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:14:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/19 23:57:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a, t_stack **b)
{
	int		position;
	int		stack_size;

	while(*a != NULL)
	{
		position = find_smallest(*a);
		stack_size = find_stack_size(*a);
		// printf("pos: %d\n", position);
		// printf("size: %d\n", stack_size);
		if (position < stack_size/2 && position != 0)
			while (position-- > 0)
				ra(a, 1);
		else if (position >= stack_size/2 && position != 0)
			while (++position <= stack_size)
				rra(a, 1);
		pb(b, a, 1);
		// printList(*a);
	}
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
	int	position;
	int	smallest_position;
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


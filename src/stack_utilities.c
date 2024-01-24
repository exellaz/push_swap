/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:10:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/24 22:28:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack->value != target && (stack))
	{
		stack = (stack)->next;
		// printf("Hi %d, stack value: %d\n", pos, stack->value);
		pos++;
	}
	return (pos);
}

t_stack	*find_max_node(t_stack *stack)
{
	int	max;
	t_stack *max_node;

	max = INT_MIN;
	while (stack)
	{
		if (max < stack->value)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *stack)
{
	int	min;
	t_stack *min_node;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->value)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_last(t_stack *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

// void	free_all(t_data *data)
// {
// 	free(data->a);
// 	free(data->b);
// 	free(data);
// }

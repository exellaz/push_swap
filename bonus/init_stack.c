/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 21:40:39 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	init_stack_a(t_stack **a, char **input, int ac)
{
	int	nbr;
	int	i;

	i = 0;
	while (input[i])
	{
		nbr = ft_atoi(input[i++]);
		append_node(a, nbr);
	}
	if (ac == 2)
		free_arrays(input);
	return (i);
}

void	init_struct(t_data *data, t_stack **a, t_stack **b, int size)
{
	data->a = a;
	data->b = b;
	data->size_a = size;
	data->size_b = 0;
	data->total_size = size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 15:17:39 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

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

int	init_stack_a(t_stack **a, int ac, char **av)
{
	int	nbr;
	int	i;
	char **temp_array;

	temp_array = 0;
	i = 0;
	if (ac == 2)
	{
		temp_array = ft_split(av[1], ' ');
		while (temp_array[i])
		{
			nbr = ft_atoi(temp_array[i++]);
			append_node(a, nbr);
		}
		free(temp_array);
	}
	else
	{
		while (av[i + 1])
		{
			nbr = ft_atoi(av[++i]);
			append_node(a, nbr);
		}
	}
	return (i);
}

void printList(const t_stack *head)
{
    const t_stack *current = head;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void	init_struct(t_data *data, t_stack **a, t_stack **b, int size)
{
	data->a = a;
	data->b = b;
	data->size_a = size;
	data->size_b = 0;
	data->total_size = size;
}

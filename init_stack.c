/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/11 22:57:51 by kkhai-ki         ###   ########.fr       */
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

void	init_stack_a(t_stack **a, int ac, char **av)
{
	int	nbr;
	int	i;
	char **temp_array;

	temp_array = 0;
	if (ac == 2)
	{
		temp_array = ft_split(av[1], ' ');
		i = 0;
		while (temp_array[i])
		{
			nbr = ft_atoi(temp_array[i]);
			append_node(a, nbr);
			i++;
		}
		free(temp_array);
	}
	else
	{
		i = 1;
		while (av[i])
		{
			nbr = ft_atoi(av[i]);
			append_node(a, nbr);
			i++;
		}
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:20:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/23 01:30:36 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **av)
{
	int	i;
	int	j;

	if (!av)
		return (1);
	i = -1;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+' || ft_isdigit(av[i][j]))
				j++;
			while (ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] != '\0')
				return (1);
		}
	}
	return (0);
}

int	check_dupe(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = i;
		while (av[++j])
			if (!ft_strcmp(av[i], av[j]))
				return (1);
	}
	return (0);
}

char	**get_input(int ac, char **av)
{
	char	**numbers;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!check_input(numbers) && !check_dupe(numbers))
			return (numbers);
	}
	else
		if (!check_input(av + 1) && !check_dupe(av + 1))
			return (av + 1);
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack *head;

	head = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			*stack = head;
			return (0);
		}
		*stack = (*stack)->next;
	}
	*stack = head;
	return (1);
}

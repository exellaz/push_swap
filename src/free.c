/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:36:47 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 13:37:06 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_all(t_data *data)
{
	if (data->a != NULL)
		free_stack(*data->a);
	if (data->b != NULL)
		free_stack(*data->b);
	free(data);
}

void	free_arrays(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:20:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/05 17:10:09 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_instructions(t_data *data)
{
	char	*instruction;
	char	*temp;
	int		error;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		temp = ft_strtrim(instruction, "\n");
		error = do_operation(data, temp);
		free(temp);
		if (error != 0)
			return ;
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(data->a) && data->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	do_operation(t_data *data, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		ra(data->a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(data->b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(data);
	else if (ft_strcmp(op, "rra") == 0)
		rra(data->a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(data->b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(data);
	else if (ft_strcmp(op, "sa") == 0)
		sa(data->a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(data->b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(data);
	else if (ft_strcmp(op, "pa") == 0)
		pa(data);
	else if (ft_strcmp(op, "pb") == 0)
		pb(data);
	else
		return (ft_printf("Invalid Instruction\n"));
	return (0);
}

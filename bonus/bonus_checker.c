/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/12 20:11:18 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	char	**input;
	int		size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		input = get_input(ac, av);
		if (!input)
			return (write(2, "Error\n", 6));
		size = init_stack_a(&a, input, ac);
		data = malloc(sizeof(t_data));
		init_struct(data, &a, &b, size);
		check_instructions(data);
		free(data);
	}
	return (0);
}

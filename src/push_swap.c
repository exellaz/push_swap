/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/02/04 22:51:13 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (is_sorted(&a))
			return (0);
		data = malloc(sizeof(t_data));
		init_struct(data, &a, &b, size);
		do_sort(data);
		free_all(data);
	}
	return (0);
}

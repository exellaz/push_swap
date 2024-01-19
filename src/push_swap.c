/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 15:15:31 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data *data;
	int	size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		data = malloc(sizeof(t_data));
		size = init_stack_a(&a, ac, av);
		init_struct(data, &a, &b, size);
		pre_sort(data);
		partition_in_b(data, (data->total_size / 20) + 25, 1, 0);
		sort_back(data);
	}
}

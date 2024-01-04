/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:52 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data *data;
	int		print;

	data = malloc(sizeof(t_data));
	print = 1;
	a = NULL;
	b = NULL;
	data->a = &a;
	data->b = &b;
	data->size_a = 100;
	data->size_b = 0;
	data->total_size = 100;
	if (ac > 1)
	{
		init_stack_a(&a, av);
	}
	pre_sort(data);
	// // printList(a);
	make_chunks(data, data->total_size / 4, 1, 0);
	// pa(data, 1);
	// pa(data, 1);
	// printList(a);
	// printList(b);
	// ss(data->a, data->b, 1);
	sort_back(data);
	// printList(a);
	// printList(b);
}

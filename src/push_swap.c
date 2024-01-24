/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/24 18:06:37 by kkhai-ki         ###   ########.fr       */
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
		if (check_input(get_input(ac, av)))
			return (write(2, "Error\n", 6));
		size = init_stack_a(&a, get_input(ac, av));
		if (is_sorted(&a))
			return (1);
		init_struct(data, &a, &b, size);
		do_sort(data);
		// free_all(data);
		// free(data);
	}
	return (0);
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

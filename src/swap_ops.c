/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:57:20 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/24 18:22:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	ft_printf("ss\n");
}

// void	swap(t_stack **head) //Define a function that swaps the positions of the top node and second node of a stack
// {
// 	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
// 		return ;
// 	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
// 	(*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
// 	(*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
// 	if ((*head)->next) //Check if there's a `next` node after the `new head` and
// 		(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
// 	(*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
// 	(*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
// }

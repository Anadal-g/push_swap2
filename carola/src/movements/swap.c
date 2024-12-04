/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:19 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/28 13:46:24 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack, int print, const char *move)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (print)
		write(1, move, ft_strlen(move));
}

void	sa(t_stack *a)
{
	swap(a, 1, "sa\n");
}

void	sb(t_stack *b)
{
	swap(b, 1, "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 0, NULL);
	swap(b, 0, NULL);
	write(1, "ss\n", 3);
}

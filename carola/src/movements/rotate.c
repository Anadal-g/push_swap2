/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:23 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/30 10:41:01 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack, int print, const char *move)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	stack->top = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, move, ft_strlen(move));
}

void	ra(t_stack *a)
{
	rotate(a, 1, "ra\n");
}

void	rb(t_stack *b)
{
	rotate(b, 1, "rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0, NULL);
	rotate(b, 0, NULL);
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:32 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/30 10:48:07 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, int print, const char *move)
{
	t_node	*last;
	t_node	*prev;

	if (stack->size < 2)
		return ;
	last = stack->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (print)
		write(1, move, ft_strlen(move));
}

void	rra(t_stack *a)
{
	reverse_rotate(a, 1, "rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b, 1, "rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0, NULL);
	reverse_rotate(b, 0, NULL);
	write(1, "rrr\n", 4);
}

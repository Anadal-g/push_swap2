/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:05 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/29 13:07:04 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *from, t_stack *to, int print, const char *move)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;
	from->size--;
	to->size++;
	if (print)
		write(1, move, ft_strlen(move));
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a, 1, "pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b, 1, "pb\n");
}

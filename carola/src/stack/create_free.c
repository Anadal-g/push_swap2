/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:03:41 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/30 10:49:31 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Entrada no válida: no es un número entero.");
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
// crea un nuevo nodo, asigna el valor y lo inicializa

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}
// inicializa una estructura t_stack con top en NULL y tamaño 0

void	push_stack(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (!new_node)
	{
		error_exit("Error: no se pudo asignar memoria para el nodo");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	last = stack->top;
	if (last == NULL)
		stack->top = new_node;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	stack->size++;
}
// añade un nuevo nodo en la parte superior de la pila

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
	{
		error_exit("Error. Stack vacio");
		exit(EXIT_FAILURE);
	}
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}
// elimina y devuelve el valor del nodo en la parte superior de la pila

void	free_list(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
// libera toda la memoria ocupada por los nodos y la estructura de la pila

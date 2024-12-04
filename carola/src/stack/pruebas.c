/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:28:44 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/04 13:37:50 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void parse_arguments(int argc, char **argv, t_stack **a)
{
    char **split;
    int i;
    int j;
    long num;

    if (!(*a))
    {
        error_exit("Error al inicializar stack.");
    }
    i = 1;
    while (i < argc)
    {    
        split = ft_split(argv[i], ' ');
        if (!split)
            error_exit("Error al dividir argumentos.");
        j = 0;
        while (split[j])
        {
            num = ft_atol(split[j]);
            if (num < INT_MIN || num > INT_MAX)
            {
                free_split(split);
                error_exit("Error: Número fuera de rango.");
            }
            if (lst_getindex(num, (*a)->top) != -1)
            {
                free_split(split);
                error_exit("Error: Número duplicado detectado.");
            }
            push_stack(*a, num);
            j++;
        }
        free_split(split);
        i++;
    }
}




void	radix(t_stack *a, t_stack *b)
{
    int		max_index;
    int		bin_digits;
    int		i, j;
    int		stack_size;

    assign_indices(a);
    max_index = find_max_index(a);
    bin_digits = calculate_max_bits(max_index);
    stack_size = a->size;
    i = 0;
    while (i < bin_digits)
    {
        j = 0;
        while (j < stack_size)
        {
            if (((a->top->index >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
            while (b->size > 0)
                pa(a, b);	
        i++;
    }
    while (b->size > 0)
        pa(a, b);
    if (!is_sorted(a))
        error_exit("Error: No se ordenó correctamente.");
}

int	ft_listsize(t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int	lst_getmin(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	lst_getmax(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	lst_maxindex(t_node *stack)
{
	t_node	*aux;
	t_node	*max;

	aux = stack->next;
	max = stack;
	while (aux)
	{
		if (aux->index > max->index)
			max = aux;
		aux = aux->next;
	}
	return (max->index);
}

int	lst_getindex(long num, t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		if (aux->value == num)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	if (!stack || !stack->top)
		return;
	current = stack->top;
	while (current)
	{
		int rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}
void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

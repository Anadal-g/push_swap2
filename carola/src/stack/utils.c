/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:45:57 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/04 13:49:13 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

long	validate_max_min(const char **str, long result, int sign)
{
	while (**str >= '0' && **str <= '9')
	{
		if (sign == 1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MAX);
		if (sign == -1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MIN);
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	const char *temp = str;
	while (*temp)
	{
		if (!ft_isdigit(*temp) && *temp != ' ' && *temp != '-' && *temp != '+')
		{
			printf("Error: no es un número válido\n");
			exit(EXIT_FAILURE);
		}
		temp++;
	}
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = validate_max_min(&str, result, sign);
	if (*str)
		error_exit("Error: no es un número entero.");
	if (sign == -1)
		result = -result;
	return (result);
}

//mirar si son solo numeros

int	duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
//comprobar si hay repetidos

void	error_exit(const char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
//mensaje de error y salida del programa

int	calculate_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
//calcular el numerode bits para saber el numero de iteraciones necesario

int	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (1);
}
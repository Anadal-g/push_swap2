/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:14 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/04 10:48:29 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_node //para representar el nodo en stack
{
	int				value;
	struct s_node	*next;
	int	index;
	
}		t_node;

typedef struct s_stack //para represertar el stack completo
{
	t_node	*top;
	int		size;
}	t_stack;

//moves
void	swap(t_stack *stack, int print, const char *move);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	push(t_stack *from, t_stack *to, int print, const char *move);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rotate(t_stack *stack, int print, const char *move);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack, int print, const char *move);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//create_free
t_node	*create_node(int value);
t_stack	*init_stack(void);
void	push_stack(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_list(t_stack *stack);

//utils
int		is_sorted(t_stack *a);
long	validate_max_min(const char **str, long result, int sign);
long	ft_atol(const char *str);
int		duplicates(t_stack *a);
void	error_exit(const char *message);
int		calculate_max_bits(int max_num);
int		print_stack(t_stack *stack);

//arguments
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_small_stack(t_stack *a, t_stack *b);
void	process_bits(t_stack *a, t_stack *b, int i);
void	sort_large_stack(t_stack *a, t_stack *b);


//main
void	validate_argu(int argc, char **argv);
void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b);
void	sort_stack(t_stack *a, t_stack *b);
int		find_max(t_stack *a);
int		main(int argc, char **argv);

//pruebas
void	parse_arguments(int argc, char **argv, t_stack **a);
void	radix(t_stack *a, t_stack *b);
int		ft_listsize(t_node *stack);
int		lst_getmin(t_stack *stack);
int		lst_getmax(t_stack *stack);
int		lst_maxindex(t_node *stack);
int		lst_getindex(long num, t_node *stack);
int		find_max_index(t_stack *stack);
void	assign_indices(t_stack *stack);
void	free_split(char **split);

#endif
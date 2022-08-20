/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:14:22 by cigarcia          #+#    #+#             */
/*   Updated: 2022/08/20 02:39:49 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size;
	int		aitems;
	int		bitems;
	char	*instructions;
}			t_stack;

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

int			split_len(char **split);
void		sort(t_stack *stack);
void		add_instruction(t_stack *stack, char *instruction);
void		quit(int code, char *message);
void		print_stacks(t_stack *stack);
void		free_split(char **split);
void		free_all(t_stack *stack, char **nums);
void		normalize_stack(t_stack *stack, int j, int n, int i);
int			is_sorted(t_stack *stack);
long long	ft_atol(const char *str);
int			valid_num(char *num);
void		panic1(t_stack *stack, char **nums);

#endif
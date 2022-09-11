/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 06:12:20 by cigarcia          #+#    #+#             */
/*   Updated: 2022/09/11 20:05:09 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->aitems - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	add_instruction(stack, "ra\n");
}

void	rb(t_stack *stack)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->bitems - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	add_instruction(stack, "rb\n");
}

void	rr(t_stack *stack)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	i = 0;
	tmp = stack->b[0];
	while (i < stack->size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	add_instruction(stack, "rr\n");
}

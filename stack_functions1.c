/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 05:57:04 by cigarcia          #+#    #+#             */
/*   Updated: 2022/09/11 20:05:34 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Swaps the two numbers at the top of stack A */
void	sa(t_stack *stack)
{
	long	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	add_instruction(stack, "sa\n");
}

/** Swaps the two numbers at the top of stack B */
void	sb(t_stack *stack)
{
	long	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	add_instruction(stack, "sb\n");
}

/** Swaps the two numbers at the top of stack A
 * and does the same on the stack B */
void	ss(t_stack *stack)
{
	long	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	add_instruction(stack, "ss\n");
}

/** Push number at the top of the stack B to the top of the stack A */
void	pa(t_stack *stack)
{
	int	i;

	if (!stack->bitems)
		return ;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = 0;
	stack->aitems++;
	stack->bitems--;
	add_instruction(stack, "pa\n");
}

/** Push number at the top of the stack A to the top of the stack B */
void	pb(t_stack *stack)
{
	int	i;

	if (!stack->aitems)
		return ;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = 0;
	stack->bitems++;
	stack->aitems--;
	add_instruction(stack, "pb\n");
}

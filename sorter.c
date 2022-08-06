/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 06:55:50 by cigarcia          #+#    #+#             */
/*   Updated: 2022/08/02 00:39:33 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a < c && a > b)
		sa(stack);
	else if (a > c && a < b)
		rra(stack);
	else if (b < a && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (c < a && c > b)
		ra(stack);
	else if (c > a && c < b)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_4(__unused t_stack *stack)
{
	while (stack->a[0] != 4)
		ra(stack);
	pb(stack);
	sort_3(stack);
	pa(stack);
	ra(stack);
}

void	sort_5(t_stack *stack)
{
	if (stack->a[3] == 5 || stack->a[4] == 5)
		while (stack->a[0] != 5)
			rra(stack);
	else
		while (stack->a[0] != 5)
			ra(stack);
	pb(stack);
	sort_4(stack);
	pa(stack);
	ra(stack);
}

void	sort_5_or_less(t_stack *stack)
{
	if (stack->size == 1)
		return ;
	else if (stack->size == 2)
	{
		if (!is_sorted(stack))
			sa(stack);
	}
	else if (stack->size == 3)
		sort_3(stack);
	else if (stack->size == 4)
		sort_4(stack);
	else if (stack->size == 5)
		sort_5(stack);
}

void	sort(t_stack *stack)
{
	int	n;
	int	i;

	if (stack->size <= 5)
	{
		sort_5_or_less(stack);
		return ;
	}
	n = 1;
	while (!is_sorted(stack))
	{
		i = 0;
		while (i < stack->size)
		{
			if (!(stack->a[0] & n))
				pb(stack);
			else if (stack->aitems > 1)
				ra(stack);
			i++;
		}
		n <<= 1;
		while (stack->bitems)
			pa(stack);
	}
}

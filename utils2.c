/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:04:03 by cigarcia          #+#    #+#             */
/*   Updated: 2022/09/11 20:04:33 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power(int base, int exp)
{
	if (!exp)
		return (1);
	else if (exp == 1)
		return (base);
	else if (exp == 2)
		return (base * base);
	else
		return (base * power(base, exp - 1));
}

void	normalize2(t_stack *stack, long *arr)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->a[i] = arr[i] + 1;
		i++;
	}
}

void	normalize_stack(t_stack *stack, int j, int n, int i)
{
	long	smallest;
	long	*arr;

	arr = ft_calloc(stack->size, sizeof(int));
	while (j < stack->size)
	{
		i = 0;
		smallest = __LONG_MAX__;
		while (i < stack->size)
		{
			if ((long)(stack->a[i]) < smallest)
			{
				smallest = stack->a[i];
				n = i;
			}
			i++;
		}
		stack->a[n] = __LONG_MAX__;
		arr[n] = j++;
	}
	normalize2(stack, arr);
	free(arr);
}

char	**get_nums(char **argv, int numc)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_calloc(numc + 1, sizeof(char *));
	while (i < numc)
	{
		nums[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (nums);
}

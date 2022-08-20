/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:28:39 by cigarcia          #+#    #+#             */
/*   Updated: 2022/08/20 02:40:37 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ignore(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

long long	ft_atol(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (ignore(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - 48);
	num *= sign;
	return (num * (!(sign == 1 && num < 0)) * (!(sign == -1 && num > 0))
		- (sign == 1 && num < 0));
}

int	valid_num(char *num)
{
	long long	a;
	long long	b;

	a = ft_atoi(num);
	b = ft_atol(num);
	if (a == b)
		return (1);
	return (0);
}

void	panic1(t_stack *stack, char **nums)
{
	int	i;

	free(stack->a);
	free(stack);
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
	quit(0, "Error\n");
}

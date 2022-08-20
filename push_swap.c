/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:13:12 by cigarcia          #+#    #+#             */
/*   Updated: 2022/08/20 02:38:56 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_input(char **input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && !(input[i][j] == '-'
					&& ft_isdigit(input[i][j + 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->a[i] == stack->a[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_stack	*new_stack(char **nums)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	stack->size = split_len(nums);
	stack->aitems = stack->size;
	stack->bitems = 0;
	stack->a = ft_calloc(stack->size + 1, sizeof(long));
	while (i < stack->size)
	{
		if (valid_num(nums[i]))
			stack->a[i] = ft_atoi(nums[i]);
		else
			panic1(stack, nums);
		i++;
	}
	stack->b = ft_calloc(stack->size + 1, sizeof(long));
	stack->instructions = ft_calloc(1, 1);
	return (stack);
}

char	**get_nums(char **argv, int numc);

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**nums;

	if (!(argc > 1))
		quit(0, "");
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = get_nums(argv, argc - 1);
	if (!verify_input(nums))
	{
		free_all(NULL, nums);
		quit(0, "Error\n");
	}
	stack = new_stack(nums);
	if (!verify_stack(stack))
	{
		free_all(stack, nums);
		quit(0, "Error\n");
	}
	normalize_stack(stack, 0, 0, 0);
	if (!is_sorted(stack))
		sort(stack);
	ft_printf(stack->instructions);
	free_all(stack, nums);
}

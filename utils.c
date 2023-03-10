/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 06:28:27 by cigarcia          #+#    #+#             */
/*   Updated: 2022/09/11 20:03:12 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	add_instruction(t_stack *stack, char *instruction)
{
	char	*new_set;

	new_set = ft_strjoin(stack->instructions, instruction);
	free(stack->instructions);
	stack->instructions = new_set;
}

void	quit(int code, char *message)
{
	if (ft_strncmp(message, "Error\n", 6))
		ft_printf(message);
	else
		ft_putstr_fd(message, 2);
	exit(code);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_all(t_stack *stack, char **nums)
{
	if (stack)
	{
		free(stack->a);
		free(stack->b);
		free(stack->instructions);
		free(stack);
	}
	free_split(nums);
}

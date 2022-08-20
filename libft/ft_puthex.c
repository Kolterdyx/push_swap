/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:51:08 by cigarcia          #+#    #+#             */
/*   Updated: 2022/07/06 05:37:17 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int num, char c)
{
	char	*numstr;
	char	*base;
	int		size;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	numstr = ft_itoa_base(num, 0, base);
	ft_putstr_fd(numstr, 1);
	size = ft_strlen(numstr);
	free(numstr);
	return (size);
}

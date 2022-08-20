/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:50:52 by cigarcia          #+#    #+#             */
/*   Updated: 2022/04/25 20:03:59 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = ((unsigned char *)dst);
	s = ((unsigned char *)src);
	if (!dst && !src && len)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (dst < src)
			d[i] = s[i];
		else
			d[len - i - 1] = s[len - i - 1];
		i++;
	}
	return (dst);
}

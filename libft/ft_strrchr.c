/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 05:38:03 by cigarcia          #+#    #+#             */
/*   Updated: 2022/04/25 20:04:19 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	ptr = NULL;
	while (*((char *)s) != '\0')
	{
		if (*(unsigned char *)s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cigarcia <cigarcia@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:28:41 by cigarcia          #+#    #+#             */
/*   Updated: 2022/04/25 20:04:15 by cigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (!s)
		return (NULL);
	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new || !f)
		return (NULL);
	ft_strlcpy(new, s, ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}

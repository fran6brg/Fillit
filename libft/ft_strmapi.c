/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:58:12 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 05:29:30 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*new_s;

	if (s && f)
	{
		i = ft_strlen(s);
		if ((new_s = malloc(sizeof(char) * i + 1)) == NULL)
			return (NULL);
		new_s[i] = '\0';
		i = 0;
		while (s[i])
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}

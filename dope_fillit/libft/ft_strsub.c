/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 05:30:28 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 05:40:23 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*sub;

	if (!s)
		return ((char *)NULL);
	i = 0;
	while (s[i])
	{
		if (i == start)
		{
			if ((sub = malloc(sizeof(char) * len + 1)) == NULL)
				return (NULL);
			j = 0;
			sub[len] = '\0';
			while (j < len)
			{
				sub[j] = s[i + j];
				j++;
			}
			return (sub);
		}
		i++;
	}
	return ((char *)NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:04:39 by fberger           #+#    #+#             */
/*   Updated: 2018/11/21 23:39:34 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (s1 && s2)
	{
		j = ft_strlen(s1);
		join = malloc(sizeof(char) * (j + ft_strlen(s2) + 1));
		if (join == NULL)
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			join[i] = s1[i];
		i = -1;
		while (s2[++i] != '\0')
			join[j + i] = s2[i];
		join[j + i] = '\0';
		return (join);
	}
	return (NULL);
}

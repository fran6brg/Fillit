/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:56:00 by fberger           #+#    #+#             */
/*   Updated: 2018/11/13 18:56:26 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	while (s1[++i] != '\0')
		;
	if ((str = malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = s1[i];
		i--;
	}
	return (str);
}

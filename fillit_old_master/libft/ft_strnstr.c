/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:03:33 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 04:04:15 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *m, const char *a, size_t n)
{
	size_t i;
	size_t j;

	i = -1;
	if (ft_strlen(a) == 0)
		return ((char *)m);
	while (m[++i] != '\0' && i < n)
	{
		j = 0;
		while (a[j] && a[j] == m[i + j] && (i + j) < n)
			j++;
		if (a[j] == '\0')
			return (((char *)m) + i);
	}
	return (NULL);
}

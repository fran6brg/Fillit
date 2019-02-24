/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:09:55 by fberger           #+#    #+#             */
/*   Updated: 2018/11/16 23:29:42 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i == n && s1[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:11:41 by fberger           #+#    #+#             */
/*   Updated: 2018/11/10 17:44:38 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len && src[i] != '\0')
		dest[i] = src[i];
	i--;
	while (++i < len)
		dest[i] = '\0';
	return (dest);
}

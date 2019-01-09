/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 03:50:10 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 05:18:48 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if ((ptr = malloc(sizeof(*ptr) * size + 1)) == NULL)
		return (NULL);
	while (i <= size)
		ptr[i++] = '\0';
	return (ptr);
}

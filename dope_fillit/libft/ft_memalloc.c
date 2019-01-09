/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:58:24 by fberger           #+#    #+#             */
/*   Updated: 2019/01/03 19:33:57 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if ((ptr = malloc(sizeof(ptr) * size)) == NULL)
		return (NULL);
	while (size-- > 0)
		ptr[size] = 0;
	return (ptr);
}

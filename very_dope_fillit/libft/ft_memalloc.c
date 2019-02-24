/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 02:50:58 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/27 23:37:22 by bihattay         ###   ########.fr       */
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

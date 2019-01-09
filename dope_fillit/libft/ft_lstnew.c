/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:50:12 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 07:08:07 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *element;

	if ((element = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		element->content = (void *)NULL;
		element->content_size = 0;
	}
	else
	{
		if ((element->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}

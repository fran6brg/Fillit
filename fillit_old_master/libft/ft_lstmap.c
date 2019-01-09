/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:48:51 by fberger           #+#    #+#             */
/*   Updated: 2018/11/16 21:49:49 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*element;
	t_list	*new_element;
	t_list	*broker;
	t_list	*new;

	element = lst;
	if (element)
	{
		broker = f(element);
		new_element = ft_lstnew(broker->content, broker->content_size);
		new = new_element;
	}
	else
		return (NULL);
	element = element->next;
	while (element)
	{
		broker = f(element);
		new_element->next = ft_lstnew(broker->content, broker->content_size);
		element = element->next;
		new_element = new_element->next;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 01:29:25 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/03 23:41:47 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*create_tetris_elem(int id,
		void const *content, size_t content_size)
{
	t_tetris	*elem;

	if (!(elem = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(elem->content = ft_memalloc(content_size + 1)))
		return (NULL);
	elem->id = id;
	ft_memcpy(elem->content, content, content_size);
	elem->content_size = content_size;
	elem->height = 1;
	find_directions(elem);
	elem->next = NULL;
	return (elem);
}

void		push_back_tetris(t_tetris **begin_list, int id,
		void const *content, size_t content_size)
{
	t_tetris *new;
	t_tetris *elem;

	if (!(new = create_tetris_elem(id, content, content_size)))
		return ;
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		elem = *begin_list;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = new;
	}
}

int			count_tetris(t_tetris *pieces)
{
	t_tetris	*piece;

	piece = pieces;
	while (piece->next)
		piece = piece->next;
	return (piece->id);
}

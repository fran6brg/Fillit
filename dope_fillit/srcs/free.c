/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:20:01 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/30 10:44:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map **map)
{
	int		i;

	i = -1;
	while (++i < (*map)->size)
		ft_strdel(&((*map)->set[i]));
	ft_memdel((void *)&(*map)->set);
	ft_memdel((void *)map);
}

int		free_tetris(t_tetris **tetris)
{
	t_tetris	*tmp;
	t_tetris	*curr;

	curr = *tetris;
	while (curr)
	{
		ft_memdel(&(curr->content));
		tmp = curr;
		curr = curr->next;
		ft_memdel((void *)&tmp);
	}
	return (1);
}

void	ft_free(t_tetris **tetris, t_map **map, int i)
{
	free_tetris(tetris);
	if (i == 0)
		free_map(map);
}

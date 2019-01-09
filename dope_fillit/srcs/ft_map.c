/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 05:06:51 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/03 20:17:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_map_elem(int size)
{
	int			row;
	t_map		*map;

	row = 0;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->set = (char **)ft_memalloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (row < size)
	{
		if (!(map->set[row] = ft_strnew(sizeof(char) * size)))
			return (NULL);
		map->set[row] = (char *)ft_memset((void *)map->set[row], '.', size);
		row++;
	}
	map->set[size] = NULL;
	map->size = size;
	return (map);
}

void		print_map(t_map *map, t_tetris **pieces)
{
	int		i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->set[i++]);
	ft_free(pieces, &map, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 01:32:09 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/04 23:07:35 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		if_tetris_fits(t_map *map, int row, int col, t_tetris *piece)
{
	if (map->set[row][col] != '.')
		return (0);
	row += piece->r1;
	col += piece->c1;
	if (map->set[row][col] != '.')
		return (0);
	row += piece->r2;
	col += piece->c2;
	if (map->set[row][col] != '.')
		return (0);
	row += piece->r3;
	col += piece->c3;
	if (map->set[row][col] != '.')
		return (0);
	return (1);
}

void	then_put_it(t_map *map, int row, int col, t_tetris *piece)
{
	map->set[row][col] = (char)(piece->id + 64);
	row += piece->r1;
	col += piece->c1;
	map->set[row][col] = (char)(piece->id + 64);
	row += piece->r2;
	col += piece->c2;
	map->set[row][col] = (char)(piece->id + 64);
	row += piece->r3;
	col += piece->c3;
	map->set[row][col] = (char)(piece->id + 64);
}

void	remove_tetris(t_map *map, int row, int col, t_tetris *piece)
{
	map->set[row][col] = '.';
	row += piece->r1;
	col += piece->c1;
	map->set[row][col] = '.';
	row += piece->r2;
	col += piece->c2;
	map->set[row][col] = '.';
	row += piece->r3;
	col += piece->c3;
	map->set[row][col] = '.';
}

int		solve(t_tetris *pieces, t_map *map)
{
	int			row;
	int			col;
	t_tetris	*piece;

	if (!(piece = pieces))
		return (1);
	row = -1;
	while (++row <= (map->size - piece->height))
	{
		col = -1;
		while (++col <= (map->size - piece->r_width))
		{
			if (map->set[row][col] == '.'
					&& if_tetris_fits(map, row, col, piece))
			{
				then_put_it(map, row, col, piece);
				if (solve(piece->next, map))
					return (1);
				else
					remove_tetris(map, row, col, piece);
			}
		}
	}
	return (0);
}

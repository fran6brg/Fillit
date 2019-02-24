/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:30:07 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/04 23:07:34 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	twenty_five_line(t_map **map, int *size)
{
	if (*map)
		free_map(map);
	*map = create_map_elem(*size++);
}

int		main(int argc, char **argv)
{
	int				fd;
	t_tetris		*pieces;
	t_map			*map;
	int				size;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit input_file\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	pieces = create_tetris_elem(0, "start", 5);
	if (!parse_input(fd, pieces))
	{
		ft_free(&pieces, &map, 1);
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	size = ft_sqrt((count_tetris(pieces->next)) * 4);
	map = create_map_elem(size++);
	while (!solve(pieces->next, map))
		twenty_five_line(&map, &size);
	print_map(map, &pieces);
	return (1);
}

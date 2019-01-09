/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:30:07 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/25 09:31:08 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strchr_modified(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = 0;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
		if (sptr[i] == (char)c)
			return (sptr + i);
	if ('\0' == (char)c)
		return (sptr + i);
	return ((char *)0);
}

int 		compute_vectors(int x, int y, char operator)
{
	if (operator == '/')
			return ((((y - (y / 5)) - 1) / 4) + 1 - ((((x - (x / 5)) - 1) / 4) + 1));
	else
			return ((((y - (y / 5)) - 1) % 4) + 1 - ((((x - (x / 5)) - 1) % 4) + 1));
}

void		find_directions(t_tetris *elem)
{
	int a;
	int b;
	int c;
	int d;
	char *ptr;

	ptr = (char *)elem->content;
	if (!ft_strchr(ptr, 35))
			return ;
	a = (ptr[0] == 35) ? 1 : ((ft_strchr_modified(ptr, 35) - ptr) + 1);
	ptr += (a - 1);
	b = (ft_strchr_modified(ptr, 35) - ptr) + a;
	ptr += (b - a);
	c = (ft_strchr_modified(ptr, 35) - ptr) + b;
	ptr += (c - b);
	d = (ft_strchr_modified(ptr, 35) - ptr) + c;
	elem->height += ((elem->r1 = compute_vectors(a, b, '/')) == 1);
	elem->height += ((elem->r2 = compute_vectors(b, c, '/')) == 1);
	elem->height += ((elem->r3 = compute_vectors(c, d, '/')) == 1);
	elem->c1 = compute_vectors(a, b, '%');
	elem->c2 = compute_vectors(b, c, '%');
	elem->c3 = compute_vectors(c, d, '%');
	elem->r_width = (elem->c1 + elem->c2 + elem->c3);
}

t_tetris	*create_tetris_elem(int id, void const *content, size_t content_size)
{
	t_tetris *elem;

	if (!(elem = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(elem->content = malloc(content_size)))
		return (NULL);
	elem->id = id;
	ft_memcpy(elem->content, content, content_size);
	elem->content_size = content_size;
	elem->height = 1;
	find_directions(elem);
	elem->next = NULL;
	return (elem);
}

void	push_back_tetris(t_tetris **begin_list, int id, void const *content,
		size_t content_size)
{
	t_tetris *new;
	t_tetris *elem;

	if (begin_list == NULL)
		return ;
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

int		is_tetri_valid(char *buf)
{
	int hashtags;
	int dots;
	int i;

	hashtags = 0;
	dots = 0;
	i = -1;
	while (buf[++i])
	{
		dots += (buf[i] == '#');
		if ((i + 1) == 21 && buf[i] != '\n' && buf[i] != '\0')
			return (0);
		else if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
		else if ((i + 1) != 21 && (i + 1) % 5 != 0 && buf[i] != '#'
				&& buf[i] != '.')
			return (0);
		if (buf[i] == '#')
			hashtags += ((i - 1 >= 0 && buf[i - 1] == '#')
				+ (i + 1 <= 19 && buf[i + 1] == '#')
				+ (i + 5 <= 19 && buf[i + 5] == '#')
				+ (i - 5 >= 0 && buf[i - 5] == '#'));
	}
	return ((((hashtags == 6 || hashtags == 8) && dots == 4) ? 1 : 0));
}

int parse_input(int fd, t_tetris *pieces)
{
	int   i;
	int   ret;
	char  buf[21];

	i = 0;
	while ((ret = read(fd, buf, 21)) >= 1)
	{
		if (ret < 20)
			return (0);
		buf[ret] = '\0';
		if (is_tetri_valid(buf) && ++i)
		{
			push_back_tetris(&pieces, i, buf, ft_strlen(buf));
		}
		else
			return (0);
	}
	if (buf[20] != '\0' || ret < 0 || i == 0)
		return (0);
	return (1);
}

int count_tetris(t_tetris *pieces)
{
	t_tetris  *piece;

	piece = pieces;
	while (piece->next)
		piece = piece->next;
	return (piece->id);
}

int if_tetris_fits(t_map *map, int row, int col, t_tetris *piece)
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

void then_put_it(t_map *map, int row, int col, t_tetris *piece)
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

void remove_tetris(t_map *map, int row, int col, t_tetris *piece)
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

int 				solve(t_tetris *pieces, t_map *map)
{
	int row;
	int col;
	t_tetris *piece;

	if (!(piece = pieces))
		return (1);
	row = -1;
	while (++row <= (map->size - piece->height))
	{
		col = -1;
		while (++col <= (map->size - piece->r_width))
		{
			if (map->set[row][col] == '.' && if_tetris_fits(map, row, col, piece))
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

void				print_pieces(t_tetris *pieces)
{
	t_tetris  *piece;

	piece = pieces;
	while (piece)
		piece = piece->next;
}

int main(int argc, char **argv)
{
	int				fd;
	t_tetris	*pieces;
	t_map			*map;
	int 			size;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit input_file\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	pieces = create_tetris_elem(0, "start", 5);
	if (!parse_input(fd, pieces))
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	pieces = pieces->next;
	size = ft_sqrt((count_tetris(pieces)) * 4);
	map = create_map_elem(size++);
	while(!solve(pieces, map))
		map = create_map_elem(size++);
	print_map(map);
	return (1);
}

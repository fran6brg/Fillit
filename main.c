#include "fillit.h"

// tetris list functions

char	*ft_strchr_bis(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = 0;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
	{
		if (sptr[i] == (char)c)
			return (sptr + i);
	}
	if ('\0' == (char)c)
		return (sptr + i);
	return ((char *)0);
}

void find_directions(t_tetris *elem) {
	/* code */
	int a;
	int b;
	int c;
	int d;
	char *ptr;

	ptr = (char *)elem->content;
	if (ft_strchr_bis(ptr, 35))
	{
		//printf("\n************\nptr = \n%s\n", ptr);
		//printf("ptr pour a = \n%s\n", ptr);
		a = (ft_strchr_bis(ptr, 35) - ptr) + 1;
		ptr += (a - 1);
		//printf("ptr pour b = \n%s\n", ptr);
		b = (ft_strchr_bis(ptr, 35) - ptr) + a;
		//printf("ptr pour c = \n%s\n", ptr);
		ptr += (b - a);
		c = (ft_strchr_bis(ptr, 35) - ptr) + b;
		//printf("ptr pour d = \n%s\n", ptr);
		ptr += (c - b);
		d = (ft_strchr_bis(ptr, 35) - ptr) + c;
		//printf("ptr = \n%s\n************\n", ptr);
		printf("a = %i | b = %i | c = %i | d = %i\n", a, b, c, d);
		elem->r1 = ((((b - (b / 5)) - 1) / 4) + 1) - ((((a - (a / 5)) - 1) / 4) + 1);
		elem->c1 = ((((b - (b / 5)) - 1) % 4) + 1) - ((((a - (a / 5)) - 1) % 4) + 1);
		elem->r2 = ((((c - (c / 5)) - 1) / 4) + 1) - ((((b - (b / 5)) - 1) / 4) + 1);
		elem->c2 = ((((c - (c / 5)) - 1) % 4) + 1) - ((((b - (b / 5)) - 1) % 4) + 1);
		elem->r3 = ((((d - (d / 5)) - 1) / 4) + 1) - ((((c - (c / 5)) - 1) / 4) + 1);
		elem->c3 = ((((d - (d / 5)) - 1) % 4) + 1) - ((((c - (c / 5)) - 1) % 4) + 1);
		printf("#1->2 = (%i;%i) | #2->3 = (%i;%i) | #3->4 = (%i;%i)\n", elem->r1, elem->c1, elem->r2, elem->c2, elem->r3, elem->c3);
	}
}

t_tetris	*create_tetris_elem(int id, void const *content, size_t content_size)
{
	t_tetris *elem;

	if (!(elem = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	// if (content == NULL)
	// {
	// 	elem->content = (void *)NULL;
	// 	elem->content_size = 0;
	// }
	// else
	// {
		if (!(elem->content = malloc(content_size)))
			return (NULL);
		elem->id = id;
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		find_directions(elem);
	// }
	elem->next = NULL;
	return (elem);
}

void	push_back_tetris(t_tetris **begin_list, int id, void const *content, size_t content_size)
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

// tetris format functions
int is_tetri_valid(char *buf)
{
  int hashtags;
  int i;

  hashtags = 0;
  i = -1;
  while (buf[++i])
  {
    if ((i + 1) == 21 && buf[i] != '\n' && buf[i] != '\0')
        return (0);
    else if ((i + 1) % 5 == 0 && buf[i] != '\n')
        return (0);
    else if ((i + 1) != 21 && (i + 1) % 5 != 0 && buf[i] != '#' && buf[i] != '.')
        return (0);
    else if ((i - 1 >= 0 && buf[i - 1] == '#')
            || (i + 1 <= 19 && buf[i + 1] == '#')
            || (i + 5 <= 19 && buf[i + 5] == '#')
            || (i - 5 >= 0 && buf[i - 5] == '#'))
      hashtags += (buf[i] == '#');
  }
  return ((hashtags == 4 ? 1 : 0));
}
//printf("ok buf[%i] = -%c-\n", i, buf[i]);
// {
//     printf("invalid tetri 1 | buf[%i] = -%c-\n", i, buf[i]);
//     return (0);
// }

int parse_input(int fd, t_tetris *pieces)
{
  int   i;
  int   ret;
  char  *buf;

  buf = ft_strnew(21);
  // if ((fd < 0 || read(fd, buf, 0) < 0))
  //   return (0);
  i = 0;
  while ((ret = read(fd, buf, 21)) >= 1)
	{
    buf[21] = '\0';
    //printf("\n***\n%s\n***\n", buf);
    if (is_tetri_valid(buf) && ++i)
    {
        push_back_tetris(&pieces, i, buf, ft_strlen(buf));
    }
    else
      return (0);
	}
  return (1);
}

// map
int	ft_sqrt(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i < nb && i < 46342)
		i++;
	return (i);
}

int count_tetris(t_tetris *pieces)
{
  t_tetris  *piece;

  piece = pieces;
	while (piece->next)
    piece = piece->next;
	return (piece->id);
}

t_map	*create_map_elem(int size)
{
	int		row;
	t_map	*map;

	row = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->set = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (row < size)
	{
		if (!(map->set[row] = ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		map->set[row] = (char *)ft_memset((void *)map->set[row], '.', size);
		row++;
	}
	map->set[size] = NULL;
	map->size = size;
	return (map);
}

// solve
/*int 				solve(t_tetris *pieces, t_map *map)
{
		int row;
		int col;
		t_tetris *piece;

		row = -1;
		piece = *pieces;
		while (++row <= map->size)
		{
				col = -1;
				while (++col <= map->size)
				{
						while(pieces)
						{
								if (map->set[row][col] == '.' && it_fit(piece, map, row, col))
								{
										put_it(piece, map, row, col);
										if (solve(*piece->next, map))
												return (1);
								}
								else
									ft_remove(curr, field);
						}
						col++;
				}
				row++;
		}
		return (0);
}*/

// display tetris one by one / map
void				print_pieces(t_tetris *pieces)
{
  t_tetris  *piece;

  piece = pieces;
	while (piece)
	{
    printf("pieces[%i] = -\n%s-\n", piece->id, piece->content);
    piece = piece->next;
  }
}

void				print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->set[i++]);
}

int main(int argc, char **argv)
{
  int				fd;
  t_tetris	*pieces;
	t_map			*map;
	int 			size;

  if (argc != 2) // mauvais nbr d'arguments
  {
    ft_putstr_fd("usage: fillit input_file\n", 2);
    return (0);
  }
  fd = open(argv[1], O_RDONLY);
  pieces = create_tetris_elem(0, "start", 5);
  if (!parse_input(fd, pieces)) // si mauvais format
  {
    ft_putstr_fd("error\n", 2);
    return (0);
  }
  //print_pieces(pieces); // pour debugg
	size = ft_sqrt((count_tetris(pieces)) * 4);
	map = create_map_elem(size++);
	/*while(!solve(pieces, map, 1))
			map = create_map_elem(size++);*/
	print_map(map);
  return (1);
}

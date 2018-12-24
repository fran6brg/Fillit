#include "fillit.h"

// tetris list functions
char	*ft_strchr_bis(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = 0;
	sptr = (char *)s;
//	if (*sptr == (char)c)
//		return (sptr);
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
	elem->height = 1;
	elem->width = 1;
	if (ft_strchr(ptr, 35))
	{
		if (ptr[0] == 35)
			a = 1;
		else
			a = (ft_strchr_bis(ptr, 35) - ptr) + 1;
		ptr += (a - 1);
		b = (ft_strchr_bis(ptr, 35) - ptr) + a;
		ptr += (b - a);
		c = (ft_strchr_bis(ptr, 35) - ptr) + b;
		ptr += (c - b);
		d = (ft_strchr_bis(ptr, 35) - ptr) + c;
		//printf("a = %i | b = %i | c = %i | d = %i\n", a, b, c, d);
		if ((elem->r1 = ((((b - (b / 5)) - 1) / 4) + 1)
					- ((((a - (a / 5)) - 1) / 4) + 1)) == 1)
			elem->height += 1;
		if ((elem->c1 = ((((b - (b / 5)) - 1) % 4) + 1)
					- ((((a - (a / 5)) - 1) % 4) + 1)) != 0)
			elem->width += 1;
		if ((elem->r2 = ((((c - (c / 5)) - 1) / 4) + 1)
					- ((((b - (b / 5)) - 1) / 4) + 1)) == 1)
			elem->height += 1;
		if (((elem->c2 = ((((c - (c / 5)) - 1) % 4) + 1) - ((((b - (b / 5))
									- 1) % 4) + 1)) != 0) && (elem->c1 >= 0))
			elem->width += 1;
		if ((elem->r3 = ((((d - (d / 5)) - 1) / 4) + 1)
					- ((((c - (c / 5)) - 1) / 4) + 1)) == 1)
			elem->height += 1;
		if (((elem->c3 = ((((d - (d / 5)) - 1) % 4) + 1) - ((((c - (c / 5))
									- 1) % 4) + 1)) != 0) && (elem->c3 == 1) && (elem->c2 >= 0))
			elem->width += 1;
		elem->r_width = (elem->c1 + elem->c2 + elem->c3);
		//printf("#1->2 = (%i;%i) | #2->3 = (%i;%i) | #3->4 = (%i;%i)\n", elem->r1, elem->c1, elem->r2, elem->c2, elem->r3, elem->c3);
		//printf("width is = %d | height is = %d\n\n", elem->width, elem->height);
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
	//int dots;
  int i;

  hashtags = 0;
	//dots = 0;
  i = -1;
  while (buf[++i])
  {
		//dots += (buf[i] == '.');
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
      {
				hashtags += (buf[i] == '#');
			}
  }
	//printf("dots = %i\n", dots);
	//printf("buf = -\n%s-\n", buf);
  return (((hashtags == 4 /*&& dots == 12*/) ? 1 : 0));
}

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
		//printf("ret = %i\n", ret);
		if (ret < 20)
			return (0);
    buf[21] = '\0';
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

void				print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->set[i++]);
}

// solve
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
							//printf("+test %c : map(%i;%i)\n", (char)(piece->id + 64), row, col);
							if (map->set[row][col] == '.' && if_tetris_fits(map, row, col, piece))
							{
									//printf("ok    %c : map(%i;%i)\n", (char)(piece->id + 64), row, col);
									then_put_it(map, row, col, piece);
									//print_map(map);
									if (solve(piece->next, map))
									{
											return (1);
									}
									else
									{
											//printf("- rem %c : map(%i;%i)\n", (char)(piece->id + 64), row, col);
											remove_tetris(map, row, col, piece);
									}
							}
				}
		}
		return (0);
}

// display tetris one by one / map
void				print_pieces(t_tetris *pieces)
{
  t_tetris  *piece;

  piece = pieces;
	while (piece)
	{
    //printf("pieces[%i] = -\n%s-\n", piece->id, piece->content);
    piece = piece->next;
  }
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
    ft_putstr_fd("error\n", 1);
    return (0);
  }
	pieces = pieces->next;
  //print_pieces(pieces); // pour debugg
	size = ft_sqrt((count_tetris(pieces)) * 4);
	map = create_map_elem(size++);
	// solve(pieces, map);
	// printf("stop\n");
	while(!solve(pieces, map))
	{
			//printf("INCREASE SIZE\n");
			map = create_map_elem(size++);
	}
	print_map(map);
  return (1);
}

// ./fillit ../../42FileChecker/fillit_checker/correct_file/valid_11 > t1
// cat ../../42FileChecker/fillit_checker/correct_compare/output_valid_11 > t2
// diff t1 t2

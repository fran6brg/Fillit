#include "fillit.h"

// tetris list functions
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
	map = create_map_elem(ft_sqrt((count_tetris(pieces)) * 4));
	print_map(map);
	//solve_this_bitch(pieces, map);
	//print_map(map);
  return (1);
}

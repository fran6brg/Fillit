#include "fillit.h"

void	ft_list_push_back(t_list **begin_list, void const *content, size_t content_size)
{
	t_list *nouveau;
	t_list *elem;

	if (begin_list == NULL)
		return ;
	nouveau = ft_lstnew(content, content_size);
	if (*begin_list == NULL)
		*begin_list = nouveau;
	else
	{
		elem = *begin_list;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = nouveau;
	}
}

int is_tetri_format(char *buf)
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
int parse_input(int fd, t_list *pieces)
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
    if (is_tetri_format(buf) && ++i)
    {
        ft_list_push_back(&pieces ,buf, ft_strlen(buf));
    }
    else
      return (0);
	}
  return (1);
}

void				print_pieces(t_list *pieces)
{
	int		i;
  t_list  *piece;

  printf("entered\n");
  piece = pieces;
	i = 0;
	while (piece)
	{
    printf("pieces[%i] = -\n%s-\n", i++, piece->content);
    piece = piece->next;
  }
}

int main(int argc, char **argv)
{
  int fd;
  t_list *pieces;

  if (argc != 2) // mauvais nbr d'arguments
  {
    ft_putstr_fd("usage: fillit input_file\n", 2);
    return (0);
  }
  fd = open(argv[1], O_RDONLY);
  pieces = ft_lstnew("start", 5);
  if (!parse_input(fd, pieces)) // si mauvais format
  {
    ft_putstr_fd("error\n", 2);
    return (0);
  }
  print_pieces(pieces);
  return (1);
}

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	char			**set;
	int				size;
}					  t_map;

typedef struct	   s_tetris
{
  int               id;
  void              *content;
  size_t			      content_size;
  struct s_tetris	  *next;
  // à faire enregistrer les 4 sens du tetris chacun dans une var
	int			r1;
	int			c1;
	int			r2;
	int			c2;
	int			r3;
	int			c3;
	// int 		width;
	int 		height;
	int 		r_width;
}				            t_tetris;

t_map					*create_map_elem(int size);
void					print_map(t_map *map);

#endif

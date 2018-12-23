#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_map
{
	char			**set;
	int				size;
}					  t_map;

typedef struct	   s_tetris
{
	// int			width;
	// int			height;
	// char		value;
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

}				            t_tetris;

#endif

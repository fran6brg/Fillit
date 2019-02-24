/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 01:50:00 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/04 23:05:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	char			**set;
	int				size;
}					t_map;

typedef struct		s_tetris
{
	int				id;
	void			*content;
	size_t			content_size;
	struct s_tetris	*next;
	int				r1;
	int				c1;
	int				r2;
	int				c2;
	int				r3;
	int				c3;
	int				height;
	int				r_width;
}					t_tetris;

int					solve(t_tetris *pieces, t_map *map);
int					count_tetris(t_tetris *pieces);
int					parse_input(int fd, t_tetris *pieces);
int					is_tetri_valid(char *buf);
void				find_directions(t_tetris *elem);
void				print_map(t_map *map, t_tetris **pieces);
void				ft_free(t_tetris **head, t_map **map, int i);
void				free_map(t_map **map);
void				solve_map(t_tetris *pieces, t_map **map, int size);
void				push_back_tetris(t_tetris **begin_list, int id,
		void const *content, size_t content_size);
t_map				*create_map_elem(int size);
t_tetris			*create_tetris_elem(int i, void const *c, size_t cnt_size);

#endif

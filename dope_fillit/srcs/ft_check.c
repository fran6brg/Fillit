/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 01:34:12 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/03 20:19:17 by bihattay         ###   ########.fr       */
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

int		compute_vectors(int x, int y, char operator)
{
	int		a;
	int		b;

	a = ((((y - (y / 5)) - 1) / 4) + 1 - ((((x - (x / 5)) - 1) / 4) + 1));
	b = ((((y - (y / 5)) - 1) % 4) + 1 - ((((x - (x / 5)) - 1) % 4) + 1));
	if (operator == '/')
		return (a);
	else
		return (b);
}

void	find_directions(t_tetris *elem)
{
	int		a;
	int		b;
	int		c;
	int		d;
	char	*ptr;

	ptr = (char *)elem->content;
	if (ptr && !ft_strchr(ptr, 35))
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

int		parse_input(int fd, t_tetris *pieces)
{
	int		i;
	int		ret;
	char	buf[21];

	i = 0;
	while ((ret = read(fd, buf, 21)) >= 1)
	{
		buf[ret] = '\0';
		if (ret < 20)
			return (0);
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

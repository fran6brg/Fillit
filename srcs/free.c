/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:20:01 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/24 23:24:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelist(t_tetris **head)
{
	t_tetris	*tmp;
	t_tetris	*curr;

	curr = *head;
	while (curr)
	{
		ft_strdel(curr->content);
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

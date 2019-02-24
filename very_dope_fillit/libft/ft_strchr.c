/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:39:00 by fberger           #+#    #+#             */
/*   Updated: 2018/12/30 01:51:49 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = -1;
	sptr = (char *)s;
	while (sptr && sptr[++i] != '\0')
	{
		if (sptr[i] == (char)c)
			return (sptr + i);
	}
	if ('\0' == (char)c)
		return (sptr + i);
	return ((char *)0);
}

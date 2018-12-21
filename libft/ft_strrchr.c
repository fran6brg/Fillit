/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:06:38 by fberger           #+#    #+#             */
/*   Updated: 2018/11/13 22:08:00 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*sptr;

	i = -1;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
		;
	if ('\0' == (char)c)
		return (sptr + i);
	while (--i >= 0)
	{
		if (sptr[i] == (char)c)
			return (sptr + i);
	}
	return ((char *)0);
}

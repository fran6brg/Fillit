/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:25:38 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 06:53:18 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int		i;
	int		flag;
	int		nb_str;

	i = -1;
	flag = 0;
	nb_str = 0;
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			nb_str++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
	}
	return (nb_str);
}

static int	str_len(char const *s, char c)
{
	int		i;

	i = -1;
	while (s[++i] != c && s[i] != '\0')
		;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strs;
	int		i;
	int		str;
	int		len;

	if (!s || (strs = malloc(sizeof(char **) * (count_str(s, c) + 1))) == NULL)
		return ((char **)NULL);
	i = -1;
	str = 0;
	while (s[++i])
	{
		if (s[i] != c && str < count_str(s, c))
		{
			len = str_len(&s[i], c);
			if ((strs[str] = malloc(sizeof(char) * len + 1)) == NULL)
				return ((char **)NULL);
			while (s[i] != c && s[i] != '\0')
				*(strs[str])++ = s[i++];
			*(strs[str]) = '\0';
			strs[str] = (&(*strs[str]) - len);
			str++;
		}
	}
	strs[str] = 0;
	return (strs);
}

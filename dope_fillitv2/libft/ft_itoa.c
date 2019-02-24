/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:40:59 by fberger           #+#    #+#             */
/*   Updated: 2018/11/21 23:46:43 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_index(int n)
{
	int		index;

	index = 0;
	if (n < 0)
	{
		n *= -1;
		index++;
	}
	while (++index && n >= 10)
		n /= 10;
	return (index);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		index;

	index = count_index(n);
	if (!(str = malloc(sizeof(char) * index + 1)))
		return (NULL);
	str[index--] = '\0';
	if (index == 0 && n == 0 && (str[index] = '0'))
		return (str);
	if (n == -2147483648 && ft_strcpy(str, "-2147483648"))
		return (str);
	while (index >= 0)
	{
		if (n == 0)
			str[index--] = '-';
		else
			str[index--] = (((n > 0) ? n : (n *= -1)) % 10) + 48;
		n /= 10;
	}
	return (str);
}

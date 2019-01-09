/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:09:08 by fberger           #+#    #+#             */
/*   Updated: 2018/11/21 23:43:39 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_is_over_lim(const char *str, int size, int sign)
{
	if (size > 19)
		return (1);
	else
		return (str[0] == '9' && str[1] >= '2' && str[2] >= '2' && str[3] >= '3'
		&& str[4] >= '3' && str[5] >= '7' && str[6] >= '2' && str[7] >= '0'
		&& str[8] >= '3' && str[9] >= '6' && str[10] >= '8' && str[11] >= '5'
		&& str[12] >= '4' && str[13] >= '7' && str[14] >= '7' && str[15] >= '5'
		&& str[16] >= '8' && str[17] >= '0'
		&& ((str[18] > '7' && sign == 1) || (str[18] > '8' && sign == -1)));
}

static int	nb_is_over_long(const char *str, int sign)
{
	int	i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i >= 19 && sign == 1)
		return (nb_is_over_lim(str, i, sign) ? -1 : 1);
	if (i >= 19 && sign == -1)
		return (nb_is_over_lim(str, i, sign) ? 0 : 1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;
	int				check;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	check = nb_is_over_long(str + i, sign);
	if (check != 1)
		return (check);
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb * sign);
}

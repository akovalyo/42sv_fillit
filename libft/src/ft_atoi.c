/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:29:16 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/21 15:53:54 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_double_overflow(unsigned long lng, int sign)
{
	if (lng > 9223372036854775807)
	{
		if (sign < 0)
			return (0);
		return (-1);
	}
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	collector;
	int				lng;

	sign = 1;
	collector = 0;
	lng = 0;
	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\v' ||
			*nptr == '\r' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = (*nptr == '-') ? -1 : 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		collector = collector * 10 + *nptr - '0';
		nptr++;
	}
	if ((lng = ft_double_overflow(collector, sign)) <= 0)
		return (lng);
	return ((int)collector * sign);
}

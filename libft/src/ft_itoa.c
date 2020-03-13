/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:50:28 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 16:14:00 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new;
	int		end;

	end = ft_nbrlen(n);
	new = (char *)malloc(sizeof(char) * end + 1);
	if (new == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(new, "-2147483648"));
	if (n < 0)
	{
		n = -n;
		new[0] = '-';
	}
	new[end] = '\0';
	end--;
	if (n == 0)
		new[end] = '0';
	while (n > 0)
	{
		new[end] = n % 10 + 48;
		n = n / 10;
		end--;
	}
	return (new);
}

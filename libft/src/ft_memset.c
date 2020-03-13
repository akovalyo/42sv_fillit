/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvi@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:00:15 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/18 22:18:37 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)s;
	while (n > 0)
	{
		*tmp = (unsigned char)c;
		n--;
		tmp++;
	}
	return (s);
}

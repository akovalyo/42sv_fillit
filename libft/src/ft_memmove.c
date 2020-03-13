/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:22:35 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/21 15:52:55 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i_dst;
	char			*n_dst;
	const char		*n_src;

	i_dst = len - 1;
	n_dst = (char *)dst;
	n_src = (const char *)src;
	if (!dst && !src)
		return (dst);
	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		while ((int)(--len) >= 0)
		{
			n_dst[i_dst] = n_src[len];
			i_dst--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:21:00 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/21 22:19:58 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < n && i <= src_len)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	if (i <= src_len)
		dest[dest_len] = '\0';
	return (dest);
}

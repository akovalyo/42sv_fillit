/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:42:06 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 12:14:36 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len;
	size_t i;

	len = ft_strlen(dest);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (len > size - 1)
		return (size + ft_strlen(src));
	while ((len + i < size - 1) && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + ft_strlen(src));
}

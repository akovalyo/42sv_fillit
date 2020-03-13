/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:02:00 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/21 22:22:55 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t find_index;
	size_t mem;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && len > 0)
	{
		if (len < ft_strlen(needle))
			return (NULL);
		find_index = 0;
		mem = i;
		while (haystack[mem] == needle[find_index]
				&& haystack[mem] && needle[find_index])
		{
			find_index++;
			mem++;
		}
		if (needle[find_index] == '\0')
			return ((char *)haystack + i);
		len--;
		i++;
	}
	return (NULL);
}

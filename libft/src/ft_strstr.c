/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:02:00 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 17:31:27 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t find_index;
	size_t remember;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		find_index = 0;
		if (haystack[i] == needle[find_index])
		{
			remember = i;
			while (haystack[i] == needle[find_index])
			{
				if (needle[find_index + 1] == '\0')
					return ((char *)&haystack[remember]);
				find_index++;
				i++;
			}
			i = remember;
		}
		i++;
	}
	return (0);
}

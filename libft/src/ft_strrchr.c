/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:32:53 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/20 21:35:37 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	end;

	end = ft_strlen(s);
	while (s[end] != (char)c && end >= 0)
		end--;
	if (s[end] == (char)c)
		return ((char *)&s[end]);
	return (NULL);
}

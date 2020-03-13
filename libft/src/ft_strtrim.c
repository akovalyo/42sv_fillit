/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:42:53 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 21:13:53 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int end;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > i)
	{
		j++;
		end--;
	}
	return (ft_strsub(s, i, (ft_strlen(s) - i - j)));
}

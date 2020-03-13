/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:01:24 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/26 11:31:12 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_words(char const *str, char c)
{
	int n;

	n = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			n++;
			while (*str && *str != c)
				str++;
		}
	}
	return (n);
}

static int	w_size(char const *str, char c, int i)
{
	int j;

	j = 0;
	while (str[i] && str[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static int	last_word_i(char const *s, char c, int i)
{
	while (s[i] == c)
		i--;
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
		return (i + 1);
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	char	**array;

	if (!s || !c)
		return (NULL);
	i = ft_strlen(s) - 1;
	words = total_words(s, c);
	array = (char **)malloc(words * sizeof(char *) + 1);
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	words--;
	while (i > 0)
	{
		i = last_word_i(s, c, i);
		array[words] = ft_strsub(s, i, w_size(s, c, i));
		i--;
		words--;
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:53:41 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/26 11:33:28 by akovalyo         ###   ########.fr       */
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

t_list		*ft_strsplit_lst(char const *s, char c)
{
	int		words;
	int		i;
	t_list	*new;
	t_list	*elem;

	elem = NULL;
	new = NULL;
	if (!s || !c)
		return (NULL);
	i = ft_strlen(s) - 1;
	words = total_words(s, c);
	new = (t_list *)malloc(sizeof(t_list));
	new = ft_lstnew("\0", 1);
	if (new == NULL)
		return (NULL);
	while (i > 0)
	{
		i = last_word_i(s, c, i);
		elem = ft_lstnew(ft_strsub(s, i, w_size(s, c, i)), w_size(s, c, i) + 1);
		ft_lstadd(&new, elem);
		i--;
		words--;
	}
	return (new);
}

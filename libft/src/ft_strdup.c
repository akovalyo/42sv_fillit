/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:41:15 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 10:30:38 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *d;

	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}

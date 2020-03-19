/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 10:28:30 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/19 10:28:30 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	lst_tetr_size(t_tetr *lst)
{
	int i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	sqroot(int n)
{
	int sqrt;

	sqrt = 2;
	while (sqrt * sqrt < n)
		sqrt++;
	return (sqrt);
}

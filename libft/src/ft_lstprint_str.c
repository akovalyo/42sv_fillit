/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:55:38 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 20:56:59 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_str(t_list *lst)
{
	while (lst != NULL && lst->content != NULL)
	{
		ft_putstr(lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}

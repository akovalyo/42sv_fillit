/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:34:24 by akovalyo          #+#    #+#             */
/*   Updated: 2020/02/19 20:40:55 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *next_elem;

	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		next_elem = lst->next;
		f(lst);
		lst = next_elem;
	}
}

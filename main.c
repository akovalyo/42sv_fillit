/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:00:01 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/12 11:00:01 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list *tetr_list;

	if (argc == 2)
	{
		if(!(tetr_list = read_tetr_file(argv[1])))
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		ft_lstprint_str(tetr_list);
	}
	else
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" [file]\n", 2);
	}
	return (0);
}

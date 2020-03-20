/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
	t_tetr *tetr_list;

	if (argc == 2)
	{
		if(!(tetr_list = read_tetr_file(argv[1])))
		{
			ft_putstr("ERROR WHILE READING FILE\n");
			return (0);
		}
		solve(tetr_list);
		delete_tetr_list(tetr_list);
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}

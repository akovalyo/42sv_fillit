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
			ft_putstr("ERROR\n");
			return (0);
		}
		while (tetr_list != NULL)
		{
			printf("[%d, %d], %c\n", tetr_list->x[3], tetr_list->y[3], tetr_list->letter);
			tetr_list = tetr_list->next;
		}
	}
	else
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" [file]\n", 2);
	}
	return (0);
}

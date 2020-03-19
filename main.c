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
		
		while (tetr_list != NULL)
		{
			printf("[%d, %d], %c\n", tetr_list->xy[0], tetr_list->xy[1], tetr_list->letter);
			tetr_list = tetr_list->next;
		}
		//printf("%d\n%d\n", lst_tetr_size(tetr_list), ft_sqroot(8));
		//for (int i = 4; i <= 104; i += 4)
		//	printf("%d: %d\n", i, sqroot(i));
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}

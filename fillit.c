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

int	read_tetr_file(int fd)
{
	


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		read_tetr_file(fd);
	}
	else
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" [file]\n", 2);
	}
return (0);
}

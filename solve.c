/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 10:21:27 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/19 10:21:27 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	place_tetr(t_tetr *tetr, t_map *map, char letter)
{

}

int	intersection(t_map *map, t_tetr *tetr)
{

}
int	in_map(t_tetr *tetr, int map_size, int axis)
{
	if (axis == 0)
		return (tetr->x[0] + tetr->xy[0] < map_size && \
				tetr->x[1] + tetr->xy[0] < map_size && \
				tetr->x[2] + tetr->xy[0] < map_size && \
				tetr->x[3] + tetr->xy[0] < map_size);
	else
		return (tetr->y[0] + tetr->xy[1] < map_size && \
				tetr->y[1] + tetr->xy[1] < map_size && \
				tetr->y[2] + tetr->xy[1] < map_size && \
				tetr->y[3] + tetr->xy[1] < map_size);
}

int	place_on_map(t_map *map, t_tetr *tetr, int map_size)
{
	if (!tetr)
		return (1);
	while (in_map(tetr, map_size, 1))
	{
		while (in_map(tetr, map_size, 0))
		{
			//if no intersection 
				//-> place letter
				//check recurrsion all pieces ok -> return 1
				//else place '.'
		tetr->xy[0]++;
		}
	tetr->xy[0] = 0;
	tetr->xy[1]++;
	}
	return (0);
}

int	solve(t_tetr *tetr)
{
	t_map	*map;
	int	map_size;

	map_size = sqroot(lst_tetr_size(tetr) * 4);
	map = create_map(map_size);
	while (!place_on_map(map, tetr, map_size))
	{
		delete_map(tetr, map_size);
		map_size++;
		map = create_map(map_size);
		
	}
	//print map

	delete_map(tetr, map_size);
	return (0);
}

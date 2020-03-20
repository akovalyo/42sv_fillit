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

/*
**	Places the letter of the tetromino or other character on the map
*/

void	place_tetr(t_tetr *tetr, t_map *map, char letter)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 4)
	{
		x = tetr->x[i] + tetr->xy[0];
		y = tetr->y[i] + tetr->xy[1];
		map->map[y][x] = letter;
		i++;
	}
}

/*	
**	Checks if the tetromino overlap others on the map
*/

int	intersection(t_map *map, t_tetr *tetr)
{
	int x;
	int y;
	int i;
	
	i = 0;
	x = tetr->x[i] + tetr->xy[0];
	y = tetr->y[i] + tetr->xy[1];
	while (i <= 3 && map->map[y][x] == '.')
	{
		i++;
		x = tetr->x[i] + tetr->xy[0];
		y = tetr->y[i] + tetr->xy[1];
	}
	if (i == 4)
		return (0);
	return (1);

}

/*
**	Checks if the tetromino fits the map
*/

int	in_map(t_tetr *tetr, int map_size, int axis)
{
	if (axis == 0)
		return (tetr->x[0] + tetr->xy[0] < map_size &&
				tetr->x[1] + tetr->xy[0] < map_size &&
				tetr->x[2] + tetr->xy[0] < map_size &&
				tetr->x[3] + tetr->xy[0] < map_size);
	else
		return (tetr->y[0] + tetr->xy[1] < map_size &&
				tetr->y[1] + tetr->xy[1] < map_size &&
				tetr->y[2] + tetr->xy[1] < map_size &&
				tetr->y[3] + tetr->xy[1] < map_size);
}

/*
**	Function checks and then places the tetromino if it's inside the map and doesn't
**	intersect other tetrominoes. Using recursion to check if other tetrominoes
**	in the list can be placed on the map. If it doesn't, current tetromino 
**	moves until all can be placed on the map or 0 if it fails.
*/

int	try_map(t_map *map, t_tetr *tetr, int map_size)
{
	if (!tetr)
		return (1);
	tetr->xy[0] = 0;
	tetr->xy[1] = 0;
	while (in_map(tetr, map_size, 1))
	{
		while (in_map(tetr, map_size, 0))
		{
			if (!intersection(map, tetr))
			{
				place_tetr(tetr, map, tetr->letter);
				if (try_map(map, tetr->next, map_size))
					return (1);
				else
					place_tetr(tetr, map, '.');
			}
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
	while (!try_map(map, tetr, map_size))
	{
		delete_map(map, map_size);
		map_size++;
		map = create_map(map_size);
		
	}
	print_map(map, map_size);
	delete_map(map, map_size);
	return (0);
}

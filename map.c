/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:59:02 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/19 09:59:02 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*create_map(int map_size)
{
	t_map	*map;
	int	i;
	
	i = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->map = (char **)ft_memalloc(sizeof(char *) * map_size);
	while (i < map_size)
	{
		map->map[i] = ft_strnew(map_size);
		ft_memset(map->map[i], '.', map_size);
		i++;
	}
	return (map);
}

void	delete_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

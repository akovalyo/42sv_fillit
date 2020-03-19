/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:37:55 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/13 14:37:55 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

#include <stdio.h>

# define TETR_SIZE 20

typedef struct 		s_tetr
{
	char 		letter;
	int		x[4];
	int		y[4];
	int		xy[2];
	struct s_tetr	*next;

}			t_tetr;

typedef struct		s_map
{
	char		**map;
}			t_map;

t_tetr	*create_tetr(char *tetr_peace, char letter);
int	add_tetr_to_list(char *tetr_buf, int size, t_tetr **tetr_list, int i);
t_tetr	*read_tetr_file(char *file);
int	check_tetr(char *tetr, int i, int end);
int	check_tetr_format(char *tetr, int start);
int	check_tetr_buf(char *tetr);
t_tetr	*move(t_tetr *tetr);
void	move_y(t_tetr *tetr);
void	move_x(t_tetr *tetr);
int	lst_tetr_size(t_tetr *lst);
int	sqroot(int n);
t_map	create_map(int map_size);
void	delete_map(t_map *map, int map_size);


#endif

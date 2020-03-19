/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:35:58 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/18 12:35:58 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_x(t_tetr *tetr)
{
	tetr->x[0] -= 1;
	tetr->x[1] -= 1;
	tetr->x[2] -= 1;
	tetr->x[3] -= 1;
}

void	move_y(t_tetr *tetr)
{
	tetr->y[0] -= 1;
	tetr->y[1] -= 1;
	tetr->y[3] -= 1;
	tetr->y[4] -= 1;
}

t_tetr	*move(t_tetr *tetr)
{
	while (tetr->x[0] != 0 && tetr->x[1] != 0 && \
			tetr->x[2] != 0 && tetr->x[3] != 0)
		move_x(tetr);
	while (tetr->y[0] != 0 && tetr->y[1] != 0 && \
			tetr->y[2] != 0 & tetr->y[3] != 0)
		move_y(tetr);
	return (tetr);
}

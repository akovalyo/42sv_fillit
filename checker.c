/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 11:02:39 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/18 11:02:39 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Counts the total number of sides every '#' character touches
**	and number of characters. If number of sides is 6 or 8 and number
**	of characters is 4 - check is passed, else function returns -1.
*/

int	check_tetr(char *tetr, int i, int end)
{
	int connect;
	int count;
	int start;

	connect = 0;
	start = i;
	count = 0;
	while (i < end)
	{
		if (tetr[i] == '#')
		{
			count++;
			if ((i + 1) < end && tetr[i + 1] == '#')
				connect++;
			if ((i - 1) >= start && tetr[i -1] == '#')
				connect++;
			if ((i + 5) < end && tetr[i + 5] == '#')
				connect++;
			if ((i - 5) >= start && tetr[i - 5] == '#')
				connect++;
		}
		i++;
	}
	return (((connect == 6 || connect == 8) && count < 5) ? 0 : -1);
}

/*
**	Checks if format of the tetromino is correct.
**	Returns -1 if check is failed.
*/

int	check_tetr_format(char *tetr, int start)
{
	int i;
	int end;

	i = 1;
	end = start + 19;
	while (start <= end)
	{
		if ((tetr[start] == '.' || tetr[start] == '#') && i % 5 != 0)
		{	
			start++;
			i++;
		}
		else if (tetr[start] == '\n' && i % 5 == 0)
		{
			start++;
			i++;
		}
		else
			return (-1);
	}
	return (0);
}

/*
**	Checks correct placement of ending \n or \0 of every tetromino.
**	Returns -1 if check is failed.
*/

int	check_tetr_buf(char *tetr)
{
	int i;

	i = 19;
	while (tetr[i])
	{
		if (tetr[i] != '\n' && tetr[i] != '\0')
			return (-1);
		else if (tetr[i] == '\0')
			return (0);
		i += 21;
	}
	return (0);
}

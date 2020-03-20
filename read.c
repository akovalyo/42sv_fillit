/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:02:10 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/15 18:02:10 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*create_tetr(char *tetr_piece, char letter)
{
	t_tetr	*new;
	int	xy;
	int	i;

	xy = 0;
	i = 0;
	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	while (i < 20)
	{
		if (tetr_piece[i] == '#')
		{
			new->x[xy] = (i < 5) ? i : (i % 5);
			new->y[xy] = i / 5;
			xy++;
		}
		i++;
	}
	new->letter = letter;
	// correct
	new = move(new);
	new->xy[0] = 0;
	new->xy[1] = 0;
	return (new);
}
	
int	add_tetr_to_list(char *tetr_buf, int size, t_tetr **tetr_list, int i)
{
	t_tetr	*cur;
	char	letter;
	
	letter = 'A';
	while (i < size)
	{
		if (check_tetr_format(tetr_buf, i) < 0 || check_tetr(tetr_buf, i, i + 20) < 0 || \
		check_tetr_buf(tetr_buf) < 0)
		       return (-1);
		if (letter == 'A')
		{
			*tetr_list = create_tetr(&tetr_buf[i], letter);
			cur = *tetr_list;
		}
		else
		{
			cur->next = create_tetr(&tetr_buf[i], letter);
			cur = cur->next;
		}
		letter++;
		i += 21;
	}
	cur->next = NULL;
	return (0);
}

t_tetr	*read_tetr_file(char *file)
{
	int fd;
	int byte_read;
	char tetr_buf[546];
	t_tetr *tetr_list;
	
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	ft_bzero(tetr_buf, 546);
	if ((byte_read = read(fd, tetr_buf, 546)) > 545 || byte_read < 20)
	{
		close(fd);
		return (NULL);
	}
	else
	{
		if (add_tetr_to_list(tetr_buf, byte_read, &tetr_list, 0) < 0)
			return (NULL);
	}
	close(fd);
	return (tetr_list);
}
	
	

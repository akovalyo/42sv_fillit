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

int	check_tetr(char *tetr, int i)
{
	int connect;
	int end;
	int start;

	connect = 0;
	start = i;
	end = i + 20;
	while (i < end)
	{
		if (tetr[i] == '#')
		{
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
	return ((connect == 6 || connect == 8) ? 0 : -1);
}

int	check_tetr_format(char *tetr, int start, int end)
{
	int i;

	i = 1;
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

int	add_tetr_to_list(char *tetr_buf, int tetr_size, t_list **tetr_list)
{
	char tetr[TETR_SIZE + 1];
	int i;
	t_list *new;

	i == 0;
	while (tetr_buf[i])
	{
		ft_bzero(tetr, TETR_SIZE + 1);
		if (check_tetr_format(tetr_buf, i, i + 19) < 0 && check_tetr(tetr_buf, i) < 0)
		       return (-1);
		ft_strncpy(tetr, &tetr_buf[i], TETR_SIZE);
		new = ft_lstnew(tetr, TETR_SIZE + 1);
		ft_lstadd_back(tetr_list, new);
		i += 20;
		if (tetr_buf[i] != '\n' && tetr_buf[i] != '\0')
			return (-1);
		else if (tetr_buf[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

t_list	*read_tetr_file(char *file)
{
	int fd;
	int byte_read;
	char tetr_buf[546];
	t_list *tetr_list;
	
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	ft_bzero(tetr_buf, 546);
	if ((byte_read = read(fd, tetr_buf, 546)) > 545 || byte_read < 20)
	{
		close(fd);
		return (NULL);
	}
	else
		if (add_tetr_to_list(tetr_buf, byte_read, &tetr_list) < 0)
			return (NULL);
	return (tetr_list);
}
	
	

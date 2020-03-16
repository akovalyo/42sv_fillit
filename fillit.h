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
# define TETR_SIZE 20

int	check_tetr(char *tetr, int i);
int	check_tetr_format(char *tetr, int start, int end);
int	add_tetr_to_list(char *tetr_buf, int tetr_size, t_list **tetr_list);
t_list	*read_tetr_file(char *file);

#endif

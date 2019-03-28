/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid_get_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:02:31 by oshyiata          #+#    #+#             */
/*   Updated: 2019/01/25 18:06:02 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramin		*get_cors_tetra(char *buf, char letter)
{
	t_tetramin	*res;
	int			i;
	int			j;

	res = ft_memalloc(sizeof(t_tetramin));
	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			res->crs[j].x = i % 5;
			res->crs[j].y = i / 5;
			j++;
		}
		i++;
	}
	move_crs(res);
	res->letter = letter;
	return (res);
}

int				find_connections(char *buf)
{
	int			i;
	int			connections;

	i = 0;
	connections = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				connections++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				connections++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				connections++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				connections++;
		}
		i++;
	}
	return (connections == 6 || connections == 8);
}

int				buf_validator(char *buf, int count)
{
	int			i;
	int			sharp;

	i = 0;
	sharp = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (3);
	if (count == 21 && buf[20] != '\n')
		return (4);
	while (i < 19)
	{
		if (i == 4 || i == 9 || i == 14)
			i++;
		if (!(buf[i] == '#' || buf[i] == '.'))
			return (1);
		if (buf[i] == '#')
			sharp++;
		i++;
	}
	if (sharp != 4)
		return (2);
	if (!find_connections(buf))
		return (4);
	return (0);
}

t_list			*read_file(int fd)
{
	int			count[2];
	char		buf[21];
	t_list		*list;
	t_tetramin	*tetr;
	char		letter;

	list = NULL;
	letter = 'A';
	while ((count[0] = read(fd, buf, BUFF_SIZE)) >= 20)
	{
		if (buf_validator(buf, count[0]) != 0
			|| (tetr = get_cors_tetra(buf, letter++)) == NULL)
			return (free_list(list));
		ft_lstadd(&list, ft_lstnew(tetr, sizeof(t_tetramin)));
		ft_memdel((void **)&tetr);
		count[1] = count[0];
	}
	if (count[0] != 0 || (count[1] == 21 && count[0] < 20))
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}

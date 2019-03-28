/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:03:38 by oshyiata          #+#    #+#             */
/*   Updated: 2019/01/25 18:05:46 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_crs			min_crs(t_tetramin *res)
{
	t_crs		min;
	int			i;

	i = 0;
	min.x = 3;
	min.y = 3;
	while (i < 4)
	{
		if (res->crs[i].x < min.x)
			min.x = res->crs[i].x;
		if (res->crs[i].y < min.y)
			min.y = res->crs[i].y;
		i++;
	}
	return (min);
}

void			move_crs(t_tetramin *res)
{
	t_crs		min;
	int			i;

	min = min_crs(res);
	i = 0;
	while (i < 4)
	{
		res->crs[i].x -= min.x;
		res->crs[i].y -= min.y;
		i++;
	}
}

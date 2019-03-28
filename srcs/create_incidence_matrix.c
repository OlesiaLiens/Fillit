/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_incidence_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:10:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 18:49:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static void			add_incidence(t_list *flst, t_crs crs, t_col *first)
{
	short		i;
	t_col		*tmp;
	t_row		*row;

	row = add_row_d(first, CHR);
	i = -1;
	while (++i < SIZE)
	{
		if (i != 0)
		{
			crs.x += FC[i].x - FC[i - 1].x;
			crs.y += FC[i].y - FC[i - 1].y;
		}
		tmp = first;
		while (tmp->crs.y != crs.y || tmp->crs.x != crs.x)
			tmp = tmp->r;
		add_node(row, tmp);
	}
}

static int			check_incidence(t_list *flst, t_crs crs, short side)
{
	short		i;

	i = 0;
	while (++i < SIZE)
	{
		crs.x += FC[i].x - FC[i - 1].x;
		crs.y += FC[i].y - FC[i - 1].y;
		if (crs.x > side - 1 || crs.x < 0)
			return (0);
		if (crs.y > side - 1 || crs.y < 0)
			return (0);
	}
	return (1);
}

static void			create_incidences(t_list *flst, t_col *first, short side)
{
	t_col		*tmp;

	tmp = first;
	while (tmp->n != 'h')
		tmp = tmp->r;
	while (tmp != first)
	{
		if (SIZE == 1 || check_incidence(flst, tmp->crs, side))
			add_incidence(flst, tmp->crs, first);
		tmp = tmp->r;
	}
}

static t_col		*create_col_headers(t_list *flst, short side_size)
{
	t_col		*col;
	t_col		*first;
	short		i;

	i = -1;
	first = NULL;
	while (flst)
	{
		col = add_col_r(&first);
		col->n = CHR;
		flst = NEXT;
	}
	while (++i < side_size * side_size)
	{
		col = add_col_r(&first);
		col->n = 'h';
		col->crs.x = i % side_size;
		col->crs.y = i / side_size;
	}
	return (first);
}

t_col				*create_incidence_matrix(t_list *flst, short side_size)
{
	t_col		*first;

	first = create_col_headers(flst, side_size);
	while (flst)
	{
		create_incidences(flst, first, side_size);
		flst = NEXT;
	}
	return (first);
}

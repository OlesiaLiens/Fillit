/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lnks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:31:09 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/15 17:59:51 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./fillit.h"

t_col		*get_col(void)
{
	t_col		*col;

	col = malloc(sizeof(t_col));
	if (col != 0)
	{
		col->l = col;
		col->r = col;
		col->u = col;
		col->d = col;
		col->n = 0;
		col->s = 0;
		col->crs.x = -1;
		col->crs.y = -1;
	}
	return (col);
}

t_row		*get_row(void)
{
	t_row		*row;

	row = malloc(sizeof(t_row));
	if (row != NULL)
	{
		row->l = row;
		row->r = row;
		row->u = row;
		row->d = row;
		row->col = NULL;
		row->row = row;
		row->n = 0;
	}
	return (row);
}

t_node		*get_node(void)
{
	t_node		*node;

	node = malloc(sizeof(t_node));
	if (node != 0)
	{
		node->l = node;
		node->r = node;
		node->u = node;
		node->d = node;
		node->col = NULL;
		node->row = NULL;
	}
	return (node);
}

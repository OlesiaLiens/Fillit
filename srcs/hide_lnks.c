/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_lnks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:46:36 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/23 20:20:14 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static void		hide_col(t_col *col)
{
	while (col->l->r == col && col->l != col)
	{
		col->r->l = col->l;
		col->l->r = col->r;
		col = col->d;
	}
}

static void		hide_row(t_row *row)
{
	row = row->r;
	while (row->u->d == row && row->u != row)
	{
		(row->col->s)--;
		row->d->u = row->u;
		row->u->d = row->d;
		row = row->r;
	}
}

static void		hide_rows_in_col(t_col *col)
{
	t_col	*first;

	first = col;
	col = col->d;
	while (col != first)
	{
		hide_row(((t_node*)col)->row);
		col = col->d;
	}
}

void			hide_related(t_node *node)
{
	t_node	*curr;

	hide_col(node->col);
	hide_rows_in_col(node->col);
	hide_col(node->row->col);
	hide_rows_in_col(node->row->col);
	curr = (t_node*)node->row->r;
	while (curr)
	{
		hide_col(curr->col);
		hide_rows_in_col(curr->col);
		curr = curr->r;
		if (curr == (t_node*)node->row)
			break ;
	}
}

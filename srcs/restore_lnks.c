/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_lnks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:49:27 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/23 23:46:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static void		restore_col(t_col *col)
{
	while (col->r->l != col && col->r != col)
	{
		col->l->r = col;
		col->r->l = col;
		col = col->u;
	}
}

static void		restore_row(t_row *row)
{
	row = row->l;
	while (row->d->u != row && row->d != row)
	{
		(row->col->s)++;
		row->u->d = row;
		row->d->u = row;
		row = row->l;
	}
}

static void		restore_rows_in_col(t_col *col)
{
	t_col	*first;

	first = col;
	col = col->u;
	while (col != first)
	{
		restore_row(((t_node*)col)->row);
		col = col->u;
	}
}

void			restore_related(t_node *node)
{
	t_node	*curr;

	curr = (t_node*)node->row->l;
	while (curr)
	{
		restore_rows_in_col(curr->col);
		restore_col(curr->col);
		curr = curr->l;
		if (curr == (t_node*)node->row)
			break ;
	}
	restore_rows_in_col(node->row->col);
	restore_col(node->row->col);
	restore_rows_in_col(node->col);
	restore_col(node->col);
}

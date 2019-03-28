/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lnks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 20:26:07 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/10 15:47:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

t_col		*add_col_r(t_col **first)
{
	t_col	*new;

	new = get_col();
	if (*first == NULL)
		*first = new;
	else
	{
		(*first)->l->r = new;
		new->r = *first;
		new->l = (*first)->l;
		(*first)->l = new;
	}
	return (new);
}

t_row		*add_row_d(t_col *first, char chr)
{
	t_row	*new;

	new = get_row();
	while (first->n != chr)
		first = first->r;
	first->u->d = (t_col*)new;
	new->d = (t_row*)first;
	new->u = ((t_row*)first)->u;
	first->u = (t_col*)new;
	new->col = first;
	if (new->u != (t_row*)first)
		new->n = new->u->n + 1;
	return (new);
}

void		add_node(t_row *row, t_col *col)
{
	t_node	*new;

	new = get_node();
	row->l->r = (t_row*)new;
	new->r = (t_node*)row;
	new->l = (t_node*)row->l;
	row->l = (t_row*)new;
	col->u->d = (t_col*)new;
	new->d = (t_node*)col;
	new->u = (t_node*)col->u;
	col->u = (t_col*)new;
	new->col = col;
	new->row = row;
	(col->s)++;
}

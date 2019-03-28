/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_incidence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:24:06 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/24 13:41:09 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static short	are_incidences_same(t_node *first1, t_node *first2)
{
	while ((t_row*)first1 != first1->row)
	{
		if (first1->col->crs.x != first2->col->crs.x
			|| first1->col->crs.y != first2->col->crs.y)
			return (0);
		first1 = first1->r;
		first2 = first2->r;
	}
	return (1);
}

static short	was_place_filled(t_node *node)
{
	t_node	*cmp;

	cmp = node->d;
	while ((t_col*)cmp != node->col)
	{
		if (are_incidences_same(node, cmp))
			return (1);
		cmp = cmp->d;
	}
	return (0);
}

static short	is_conflict(t_node *first1, t_node *first2)
{
	while ((t_row*)first1 != first1->row)
	{
		if (first1->col->crs.x == first2->col->crs.x
			|| first1->col->crs.y == first2->col->crs.y)
			return (1);
		first1 = first1->r;
		first2 = first2->r;
	}
	return (0);
}

static short	was_placed(t_node *node)
{
	t_node	*cmp;

	if ((t_col*)node->row->u != node->row->col)
	{
		cmp = ((t_node*)node->row)->u->r;
		while ((t_col*)cmp->row->u != node->row->col)
		{
			if (!is_conflict(node, cmp))
				return (1);
			cmp = ((t_node*)cmp->row)->u->r;
		}
	}
	return (0);
}

t_col			*get_next_incidence(t_col *curr, t_col *col)
{
	if (curr->l != col && was_place_filled((t_node*)curr)
		&& was_placed((t_node*)curr))
		while (curr->l != col && was_place_filled((t_node*)curr)
			&& was_placed((t_node*)curr))
			curr = curr->l->d->r;
	else
		curr = curr->l->d->r;
	return (curr);
}

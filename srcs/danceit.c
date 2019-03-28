/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danceit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:33:18 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/24 18:05:36 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./fillit.h"

static t_col	*get_next_fig(t_col *col)
{
	while (col->r->l != col)
		col = col->r;
	return (col);
}

/*
** Funtion to check if any figure which is not placed yet,
** have no more possible positions to place.
*/

static short	empty_figure(t_col *col)
{
	t_col	*first;

	while (col->r->l != col)
		col = col->r;
	first = col;
	while (col)
	{
		if (col->r->l == col)
			if (col->n != 'h' && col->d == col)
				return (1);
		col = col->r;
		if (col == first)
			break ;
	}
	return (0);
}

/*
** Main function with backtrack implementation of Dancing Links
** Firstly, it checks, if all figures was placed (*i != fcount);
** next, it calls get_next_fig function to get non-hided figure's position.
** Cycle while continues while all possible positions wasn't tried to
** place, or cover problem wasn't solved (*i < fcount).
** firstly saves a pointer which responses for one of possible positions
** to 'solved[n]' array for figure position; next, it hide with function
** hide_related all other positions of the figure, hide the figure, hide
** other positions of other figures which placed on the same cells and
** do it again; function restore_related reverts those changes.
*/

static short	solver(t_col *first, t_row **solution, short *i, short fcount)
{
	t_col	*col;
	t_col	*curr;

	if (*i != fcount && !empty_figure(first))
	{
		col = get_next_fig(first);
		curr = col->d->r;
		while (curr->l != col && *i < fcount)
		{
			solution[*i] = ((t_node*)curr)->row;
			hide_related((t_node*)curr);
			(*i)++;
			if (!solver(first, solution, i, fcount))
				(*i)--;
			restore_related((t_node*)curr);
			curr = get_next_incidence(curr, col);
		}
	}
	if (*i == fcount)
		return (1);
	return (0);
}

short			danceit(t_col *first, short fcount, t_row **solution)
{
	short	i;

	i = 0;
	if (solver(first, solution, &i, fcount))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:32:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 18:54:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./fillit.h"

static void		free_rows(t_col *head)
{
	t_col	*first;

	first = head;
	head = head->d;
	while (head != first)
	{
		head = head->d;
		free((t_row*)head->u);
	}
}

static void		free_nodes(t_col *head)
{
	t_col	*first;

	first = head;
	head = head->d;
	while (head != first)
	{
		head = head->d;
		free((t_node*)head->u);
	}
}

static void		free_cols(t_col *head)
{
	t_col	*first;

	first = head;
	head = head->r;
	while (head != first)
	{
		head = head->r;
		free(head->l);
	}
	free(first);
}

/*
** Function for free incidence matrix elements
*/

void			free_incidence_matrix(t_col **first)
{
	t_col	*head;

	head = *first;
	while (head->n != 'h')
	{
		free_rows(head);
		head = head->r;
	}
	while (head->n == 'h')
	{
		free_nodes(head);
		head = head->r;
	}
	free_cols(head);
	*first = NULL;
}

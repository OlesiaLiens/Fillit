/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:19:15 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/24 15:25:09 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./fillit.h"

static void		add_flst(t_flst **first, t_flst *new)
{
	t_flst	*curr;

	if (*first == NULL)
		*first = new;
	else
	{
		curr = *first;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

t_flst			*get_flst(t_flst **flst, short size, char *c)
{
	t_flst		*new;

	new = malloc(sizeof(t_flst));
	if (new == NULL)
		return (NULL);
	new->fig = malloc(sizeof(char) * size * size);
	new->crs = malloc(sizeof(t_crs) * size);
	if (new->fig == NULL || new->crs == NULL)
	{
		free(new->fig);
		free(new->crs);
		free(new);
		return (NULL);
	}
	new->size = size;
	new->chr = *c;
	(*c)++;
	new->next = NULL;
	add_flst(flst, new);
	return (new);
}

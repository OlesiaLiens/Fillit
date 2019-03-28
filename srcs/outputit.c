/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:06:31 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/24 14:08:12 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./fillit.h"

static short	xy_to_linear(t_node *node, short side)
{
	return (node->col->crs.x + (node->col->crs.y * side));
}

static void		print_res(char *result, short side)
{
	short	i;

	i = 0;
	while (i < side)
	{
		ft_printmem(result, side);
		write(1, "\n", 1);
		result += side;
		i++;
	}
}

static void		write_figs(t_row **sol, short fcount, short side, char *res)
{
	t_row	*row;
	t_node	*node;
	short	i;

	i = 0;
	while (i < fcount)
	{
		row = sol[i];
		node = (t_node*)row->r;
		while (row)
		{
			res[xy_to_linear(node, side)] = row->col->n;
			node = node->r;
			if (node == (t_node*)row)
				break ;
		}
		i++;
	}
}

void			outputit(t_row **solution, short fcount, short side)
{
	char	*result;

	result = malloc(side * side);
	ft_memset(result, '.', side * side);
	write_figs(solution, fcount, side, result);
	print_res(result, side);
	free(result);
}

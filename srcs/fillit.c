/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:02:03 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 20:32:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./fillit.h"

static short	min_side_size(short fcount)
{
	short	sum_sizes;
	short	curr;

	sum_sizes = fcount * SIZE;
	curr = 1;
	while (curr * curr < sum_sizes)
		curr++;
	return (curr);
}

/*
** Main fillit function.
** It starts from call function read_check_get_flst which validate file with
** tetraminoes and if it is valid, it saves every tetraminoes in t_flst
** structures; if file is invalid, it changes state to -4.
** Next, it calls function create_incidence_matrix, which creates incidence
** matrix using t_col, t_row, t_node structures, the incidence matrix contains
** all possible locations of all figures on the map.
** Function danceit tries to find way how to place all figures in every cell
** of matrix, each cell should be filled once; if it fails, incidence
** matrix will be freed, map size increased and process repeat.
** (as described by D. Knuth in the reference of DLX algorithm/Dancing Links).
** Function outputit prints result in stdout.
*/

void			fillit(const int fd, short *state)
{
	t_list	*flst;
	t_col	*first;
	short	side_size;
	short	fcount;
	t_row	**solution;

	flst = read_file(fd);
	!flst ? *state = -4 : 0;
	if (!flst)
		return ;
	fcount = ft_lstlen(flst);
	solution = malloc(sizeof(t_row*) * fcount);
	side_size = min_side_size(fcount);
	while (flst)
	{
		first = create_incidence_matrix(flst, side_size);
		if (danceit(first, fcount, solution))
		{
			outputit(solution, fcount, side_size);
			free(solution);
			flst = free_list(flst);
		}
		free_incidence_matrix(&first);
		side_size++;
	}
}

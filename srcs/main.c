/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:58:04 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 21:24:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	short	state;
	int		fd;

	state = 1;
	if (argc != 2)
		state = 0;
	if (state == 1 && (!argv || !argv[1]))
		state = -1;
	if (state == 1)
		fd = open(argv[1], O_RDONLY);
	if (state == 1 && (fd < 0 || (read(fd, 0, 0)) < 0))
		state = -2;
	if (state == 1)
		fillit(fd, &state);
	errproc(&state);
	return (0);
}

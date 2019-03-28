/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errproc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:23:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 21:45:01 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

void	errproc(short *state)
{
	if (*state == 0)
		ft_putstr("usage: ./fillit source_file\n");
	else if (*state != 1)
		ft_putstr("error\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:00:58 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 18:58:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_memsdel(void *mem, size_t size)
{
	if (mem != NULL)
	{
		ft_bzero(mem, size);
		ft_memdel(&*mem);
	}
}

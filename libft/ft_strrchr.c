/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:56:37 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 23:02:23 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	size_t		loc;

	i = 1;
	loc = 0;
	while (s[i - 1] != '\0')
	{
		if (s[i] == c)
			loc = i;
		i++;
	}
	if (s[loc] == c)
		return ((char*)s + loc);
	return (NULL);
}

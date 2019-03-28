/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:53:22 by oshyiata          #+#    #+#             */
/*   Updated: 2019/01/25 18:05:31 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*free_list(t_list *list)
{
	t_tetramin	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetramin *)list->content;
		ft_memdel((void **)&tetris);
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void			ft_lstrev(t_list **alst)
{
	t_list		*prev;
	t_list		*cur;
	t_list		*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

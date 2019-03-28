/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:02:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/01/25 20:17:56 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SIZE 4
# define BUFF_SIZE 21
# define NEXT flst->next
# define CHR ((t_tetramin*)flst->content)->letter
# define FC ((t_tetramin*)flst->content)->crs
# include <unistd.h>
# include "../libft/libft.h"

/*
** Structures for write coordinates of figures and columns in incudence matrix:
** t_crs
** Structure for write figres:
** t_flst
** Structures for create incidence matrix are connected by r, d, l, u pointers.
** Every nodes and rows have pointers to corresponding row and column:
** t_col, t_row, t_node
*/

typedef struct				s_crs
{
	short					x;
	short					y;
}							t_crs;

typedef struct				s_tetramin
{
	char					letter;
	t_crs					crs[4];
}							t_tetramin;

typedef struct				s_col
{
	struct s_col			*l;
	struct s_col			*r;
	struct s_col			*u;
	struct s_col			*d;
	char					n;
	short					s;
	t_crs					crs;
}							t_col;

typedef struct				s_row
{
	struct s_row			*l;
	struct s_row			*r;
	struct s_row			*u;
	struct s_row			*d;
	struct s_col			*col;
	struct s_row			*row;
	short					n;
}							t_row;

typedef struct				s_node
{
	struct s_node			*l;
	struct s_node			*r;
	struct s_node			*u;
	struct s_node			*d;
	struct s_col			*col;
	struct s_row			*row;
}							t_node;

void						fillit(const int fd, short *state);
void						errproc(short *state);
t_list						*read_file(int fd);
void						ft_lstrev(t_list **list);
void						move_crs(t_tetramin *res);
t_col						*create_incidence_matrix(t_list *flst, short side);
t_col						*add_col_r(t_col **col);
t_row						*add_row_d(t_col *first, char chr);
void						add_node(t_row *first, t_col *head);
t_col						*get_col(void);
t_row						*get_row(void);
t_node						*get_node(void);
short						danceit(t_col *first, short fcount, t_row **sol);
void						hide_related(t_node *node);
void						restore_related(t_node *node);
t_col						*get_next_incidence(t_col *curr, t_col *col);
void						outputit(t_row **sol, short fcount, short side);
t_list						*free_list(t_list *list);
void						free_incidence_matrix(t_col **first);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:13:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 17:08:05 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_link	*add_node(t_link *parent, t_path *path)
{
	t_link	*new;
	t_link	*tmpl;

	tmpl = path->start;
	while (tmpl && tmpl->next)
		tmpl = tmpl->next;
	if (!(new = (t_link*)ft_memalloc(sizeof(t_link))))
	{
		free_lem();
		exit(1);
	}
	new->room_link = parent->room_link;
	if (!path->start)
		path->start = new;
	else
		tmpl->next = new;
	return (new);
}

static int		find_path(t_path *path, t_lem *lem)
{
	t_room	*end_path;
	t_link	*tmpl;

	end_path = lem->start;
	while (!end_path->parent->room_link->end)
	{
		tmpl = end_path->parent;
		while (tmpl && tmpl->room_link->visit)
			tmpl = tmpl->next;
		if (!tmpl)
			return (1);
		else
		{
			tmpl = add_node(tmpl, path);
			tmpl->room_link->visit = 1;
		}
		end_path = tmpl->room_link;
	}
	return (0);
}

void		clear_one_path(t_path *path)
{
	t_link	*tmpl;

	while (path->start)
	{
		tmpl = path->start;
		path->start = path->start->next;
		ft_memdel((void**)&tmpl);
	}
	ft_memdel((void**)&path);
}

/*
** adds another path to the list
*/

static void		add_path(t_lem *lem)
{
	t_path	*new;
	t_path	*tmpp;

	tmpp = lem->path;
	while (tmpp && tmpp->next)
		tmpp = tmpp->next;
	if (!(new = (t_path*)ft_memalloc(sizeof(t_path))))
	{
		free_lem();
		exit(1);
	}
	new->start = NULL;
	new->next = NULL;
	if (find_path(new, lem))
	{
		clear_one_path(new);
		return ;
	}
	if (!lem->path)
		lem->path = new;
	else
		tmpp->next = new;
}

/*
** makes a list where each node is the start of a possible path
** ex : 5 parents from start = 5 potential path
*/

void			save_path(void)
{
	t_lem	*lem;
	t_link	*pstart;

	lem = get_lem();
	pstart = lem->start->parent;
	clear_visit(lem->room);
	while (pstart)
	{
		add_path(lem);
		pstart = pstart->next;
	}
}

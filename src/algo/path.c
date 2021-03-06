/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:13:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/27 15:33:54 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** in very specific cases, the last path might be one layer higher than the rest
** in this case, removes it
*/

static void		remove_longer_path(t_lem *lem)
{
	t_path	*tmpp;
	t_path	*save;

	tmpp = lem->path;
	get_shortest_size(lem);
	while (tmpp)
	{
		save = tmpp->next;
		if (tmpp->size > lem->shortest)
		{
			if (!tmpp->prev)
				lem->path = tmpp->next;
			else
				tmpp->prev->next = tmpp->next;
			clear_one_path(tmpp);
		}
		tmpp = save;
	}
}

/*
** adds a node to the current path
*/

static t_link	*add_node(t_room *parent, t_path *path)
{
	t_link	*newl;
	t_link	*tmpl;

	tmpl = path->start;
	while (tmpl && tmpl->next)
		tmpl = tmpl->next;
	if (!(newl = (t_link*)ft_memalloc(sizeof(t_link))))
	{
		free_lem();
		exit(1);
	}
	if (!path->start)
		path->start = newl;
	else
		tmpl->next = newl;
	init_link(newl, parent, tmpl);
	return (newl);
}

/*
** tries to find a path amongst the network of room
** if they are related it means they have a path from end to start
** if they have been visited they are already in use for another path
*/

static int		find_path(t_path *path, t_lem *lem)
{
	t_room	*end_path;
	t_link	*tmpl;
	int		size;

	end_path = lem->start;
	size = 0;
	while (!end_path->parent->room_link->end)
	{
		tmpl = end_path->parent;
		while (tmpl && tmpl->room_link->visit)
			tmpl = tmpl->next;
		if (!tmpl)
			return (1);
		else
		{
			size++;
			tmpl = add_node(tmpl->room_link, path);
			tmpl->room_link->visit = 1;
		}
		end_path = tmpl->room_link;
	}
	path->size = size;
	add_node(lem->end, path);
	return (0);
}

/*
** adds another path to the list
*/

static void		add_path(t_lem *lem)
{
	t_path	*newp;
	t_path	*tmpp;

	tmpp = lem->path;
	while (tmpp && tmpp->next)
		tmpp = tmpp->next;
	if (!(newp = (t_path*)ft_memalloc(sizeof(t_path))))
	{
		free_lem();
		exit(1);
	}
	init_path(newp, tmpp);
	if (find_path(newp, lem))
	{
		clear_one_path(newp);
		return ;
	}
	if (!lem->path)
		lem->path = newp;
	else
		tmpp->next = newp;
}

/*
** makes a list where each node is the start of a possible path
** ex : 5 parents from start = 5 potential path
*/

void			save_path(void)
{
	t_lem			*lem;
	t_link			*pstart;
	unsigned int	nb_path;

	lem = get_lem();
	nb_path = 0;
	pstart = lem->start->parent;
	clear_visit(lem->room);
	while (pstart && nb_path < lem->nb_ants)
	{
		add_path(lem);
		nb_path++;
		pstart = pstart->next;
	}
	remove_longer_path(lem);
}

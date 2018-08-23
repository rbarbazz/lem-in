/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:49:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 12:28:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** frees the first node of lem->map
*/

void		free_node_map(t_lem *lem)
{
	t_map	*tmp;

	tmp = lem->map;
	lem->map = lem->map->next;
	ft_strdel(&tmp->line);
	ft_memdel((void**)&tmp);
}

static void	free_room(t_room *room)
{
	t_room	*tmpr;
	t_link	*tmpl;

	tmpr = room;
	while (room)
	{
		tmpr = room;
		room = room->next;
		ft_strdel(&tmpr->name);
		tmpl = tmpr->link;
		while (tmpr->link)
		{
			tmpl = tmpr->link;
			tmpr->link = tmpr->link->next;
			ft_memdel((void**)&tmpl);
		}
		tmpl = tmpr->parent;
		while (tmpr->parent)
		{
			tmpl = tmpr->parent;
			tmpr->parent = tmpr->parent->next;
			ft_memdel((void**)&tmpl);
		}
		ft_memdel((void**)&tmpr);
	}
}

static void	free_full_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (map)
	{
		tmp = map;
		map = map->next;
		ft_strdel(&tmp->line);
		ft_memdel((void**)&tmp);
	}
}

/*
** frees the rest of the stored map after links were parsed
*/

static void	free_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (map)
	{
		tmp = map;
		map = map->next;
		ft_strdel(&tmp->line);
		ft_memdel((void**)&tmp);
	}
}

void		free_lem(void)
{
	t_lem	*lem;

	lem = get_lem();
	free_full_map(lem->full_map);
	free_map(lem->map);
	free_room(lem->room);
}

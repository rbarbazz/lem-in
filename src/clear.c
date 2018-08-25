/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:28:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/25 16:11:49 by rbarbazz         ###   ########.fr       */
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

/*
** clears visit flag after algo for the path phase
*/

void		clear_visit(t_room *room)
{
	t_room	*tmpr;

	tmpr = room;
	while (tmpr)
	{
		tmpr->visit = 0;
		tmpr = tmpr->next;
	}
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

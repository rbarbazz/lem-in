/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:49:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/08 10:00:23 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	t_room	*tmp;

	tmp = room;
	while (room)
	{
		tmp = room;
		room = room->next;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

/*
** frees the rest of the stored map after link were parsed
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
	free_map(lem->map);
	free_room(lem->room);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:49:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 10:38:34 by rbarbazz         ###   ########.fr       */
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
	t_room	*tmp;
	t_link	*tmp1;

	tmp = room;
	while (room)
	{
		tmp = room;
		room = room->next;
		ft_strdel(&tmp->name);
		tmp1 = tmp->link;
		while (tmp->link)
		{
			tmp1 = tmp->link;
			tmp->link = tmp->link->next;
			ft_memdel((void**)&tmp1);
		}
		ft_memdel((void**)&tmp);
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

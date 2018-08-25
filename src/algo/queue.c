/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:53:04 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/25 16:18:00 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	remove_from_queue(t_lem *lem)
{
	t_room	*tmp;

	tmp = lem->queue;
	lem->queue = lem->queue->next_queue;
	tmp->next_queue = NULL;
}

void	add_parent(t_room *room, t_room *parent)
{
	t_link	*new;
	t_link	*tmp;

	tmp = room->parent;
	while (tmp)
	{
		if (!ft_strcmp(parent->name, tmp->room_link->name))
			return ;
		tmp = tmp->next;
	}
	tmp = room->parent;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_link*)ft_memalloc(sizeof(t_link))))
	{
		free_lem();
		exit(1);
	}
	if (!room->parent)
		room->parent = new;
	else
		tmp->next = new;
	new->room_link = parent;
	new->next = NULL;
}

/*
** adds a node to the end of the queue
*/

void	add_to_queue(t_room *node, t_room *parent)
{
	t_lem		*lem;
	t_room		*tmp;

	lem = get_lem();
	tmp = lem->queue;
	if (parent)
		add_parent(node, parent);
	if (!lem->queue)
		lem->queue = node;
	else
	{
		while (tmp && tmp->next_queue)
			tmp = tmp->next_queue;
		tmp->next_queue = node;
	}
}

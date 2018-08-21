/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:53:04 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 19:57:47 by rbarbazz         ###   ########.fr       */
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

/*
** adds a node to the end of the queue
*/

void	add_to_queue(t_room *node, t_room *parent)
{
	t_lem		*lem;
	t_room		*tmp;

	lem = get_lem();
	tmp = lem->queue;
	node->parent = parent;
	if (!lem->queue)
		lem->queue = node;
	else
	{
		while (tmp && tmp->next_queue)
			tmp = tmp->next_queue;
		tmp->next_queue = node;
	}
}

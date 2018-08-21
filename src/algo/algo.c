/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:11:55 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 11:50:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	remove_from_queue(t_lem *lem)
{
	t_room	*tmp;

	tmp = lem->queue;
	lem->queue = lem->queue->next_queue;
	tmp->next_queue = NULL;
}

/*
** adds a node to the end of the queue
*/

static void	add_to_queue(t_room *node)
{
	t_lem	*lem;
	t_room	*tmp;

	lem = get_lem();
	tmp = lem->queue;
	if (!lem->queue)
		lem->queue = node;
	else
	{
		while (tmp && tmp->next_queue)
			tmp = tmp->next_queue;
		tmp->next_queue = node;
	}
}

/*
** check if neighbours were visited yet, if not add them to the queue
*/

static void	check_neighbours(t_room *queue)
{
	t_link *tmp;

	tmp = queue->link;
	while (tmp)
	{
		if (!tmp->room_link->visit)
			add_to_queue(tmp->room_link);
		tmp = tmp->next;
	}
}

int			algo(void)
{
	t_lem	*lem;

	lem = get_lem();
	add_to_queue(lem->end);
	ft_printf("HEAD OF QUEUE %s\n", lem->queue->name);
	while (lem->queue)
	{
		if (lem->queue->start)
			return (0);
		lem->queue->visit = 1;
		check_neighbours(lem->queue);
		remove_from_queue(lem);
		if (lem->queue)
			ft_printf("HEAD OF QUEUE %s\n", lem->queue->name);
	}
	return (0);
}

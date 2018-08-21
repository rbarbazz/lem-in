/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:11:55 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 12:56:29 by rbarbazz         ###   ########.fr       */
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
** check if neighbours were visited yet or if they are in the queue already
** if not, add them to the queue
*/

static void	check_neighbours(t_room *queue)
{
	t_link	*tmp;
	t_room	*tmp1;
	int		match;

	tmp = queue->link;
	while (tmp)
	{
		tmp1 = queue;
		match = 0;
		while (tmp1)
		{
			if (!ft_strcmp(tmp1->name, tmp->room_link->name))
				match = 1;
			tmp1 = tmp1->next_queue;
		}
		if (!tmp->room_link->visit && !match)
			add_to_queue(tmp->room_link);
		tmp = tmp->next;
	}
}

static void	print_queue(t_room *queue)
{
	t_room	*tmp;

	tmp = queue;
	while (tmp)
	{
		ft_printf("%s ", tmp->name);
		tmp = tmp->next_queue;
	}
	ft_printf("\n");
}

int			algo(void)
{
	t_lem	*lem;

	lem = get_lem();
	add_to_queue(lem->end);
	print_queue(lem->queue);
	while (lem->queue)
	{
		if (lem->queue->start)
			return (0);
		lem->queue->visit = 1;
		check_neighbours(lem->queue);
		remove_from_queue(lem);
		if (lem->queue)
			print_queue(lem->queue);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:11:55 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 12:18:44 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** check if neighbours were visited yet or if they are in the queue already
** if not, add them to the queue
*/

static void	check_neighbours(t_room *queue)
{
	t_link	*tmpl;
	t_room	*tmpr;
	t_room	*match;

	tmpl = queue->link;
	while (tmpl)
	{
		tmpr = queue;
		match = NULL;
		while (tmpr)
		{
			if (!ft_strcmp(tmpr->name, tmpl->room_link->name))
				match = tmpr;
			tmpr = tmpr->next_queue;
		}
		if (!tmpl->room_link->visit && !match)
			add_to_queue(tmpl->room_link, queue);
		if (!tmpl->room_link->visit && match)
			add_parent(match, queue);
		tmpl = tmpl->next;
	}
}

static void	print_queue(t_room *queue)
{
	t_room	*tmpr;
	t_link	*tmpl;

	tmpr = queue;
	while (tmpr)
	{
		ft_printf("%s_", tmpr->name);
		tmpl = tmpr->parent;
		while (tmpl)
		{
			ft_printf("%s", tmpl->room_link->name);
			tmpl = tmpl->next;
		}
		ft_printf(" ");
		tmpr = tmpr->next_queue;
	}
	ft_printf("\n\n");
}

int			algo(void)
{
	t_lem	*lem;

	lem = get_lem();
	add_to_queue(lem->end, NULL);
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
	return (1);
}

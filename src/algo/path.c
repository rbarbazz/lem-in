/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:13:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 13:18:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_path(t_lem *lem)
{
	t_path	*new;
	t_path	*tmpp;

	tmpp = lem->path;
	while (tmpp && tmpp->next)
		tmpp = tmpp->next;
	if (!(new = (t_path*)ft_memalloc(sizeof(t_path))))
	{
		free_lem();
		exit(1);
	}
	if (!tmpp)
		tmpp = new;
	else
		tmpp->next = new;
}

static void		clear_visit(t_room *room)
{
	t_room	*tmpr;

	tmpr = room;
	while (tmpr)
	{
		tmpr->visit = 0;
		tmpr = tmpr->next;
	}
}

void			save_path(void)
{
	t_lem	*lem;
	t_link	*pstart;

	lem = get_lem();
	pstart = lem->start->parent;
	clear_visit(lem->room);
	while (pstart)
	{
		add_path(lem);
		pstart = pstart->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:08:13 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/26 18:19:45 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_link(t_link *newl, t_room *room_link, t_link *tmpl)
{
	newl->room_link = room_link;
	newl->ant = 0;
	newl->prev = tmpl;
	newl->next = NULL;
}

void	init_path(t_path *newp, t_path *tmpp)
{
	newp->start = NULL;
	newp->size = 0;
	newp->ant_min = 0;
	newp->ant_max = 0;
	newp->done = 0;
	newp->prev = tmpp;
	newp->next = NULL;
}

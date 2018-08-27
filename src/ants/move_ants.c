/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 13:57:10 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/27 11:55:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ants(t_lem *lem)
{
	t_path	*tmpp;
	t_link	*tmpl;

	tmpp = lem->path;
	while (tmpp && !tmpp->done)
	{
		tmpl = tmpp->start;
		while (tmpl)
		{
			if (!tmpl->visit && tmpl->prev->visit)
			{
				tmpl->ant = tmpp->ant_min;
				tmpl->visit = 1;
				break ;
			}
			else if (tmpl->ant && tmpl->ant == tmpp->ant_max)
				tmpl->ant = 0;
			else if (tmpl->ant)
				tmpl->ant++;
			tmpl = tmpl->next;
		}
		tmpp = tmpp->next;
	}
}

/*
** assigns the max ant to each path
*/

void	assign_max_ant(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	i = lem->nb_path - 1;
	tmpp = lem->path;
	while (tmpp)
	{
		tmpp->ant_max = lem->nb_ants - (i * (lem->nb_ants / lem->nb_path));
		if ((lem->nb_ants % lem->nb_path) && i == lem->nb_path)
			tmpp->ant_max += (lem->nb_ants % lem->nb_path);
		i--;
		tmpp = tmpp->next;
	}
}

/*
** assigns ant numbers to each path and the max ant they are handling
** also set visit for first rooms to 1
*/

void	assign_first_ant(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	i = lem->nb_path;
	tmpp = lem->path;
	while (tmpp)
	{
		tmpp->start->ant = 1 + lem->nb_ants - (i * (lem->nb_ants /\
		lem->nb_path));
		if ((lem->nb_ants % lem->nb_path) && i == lem->nb_path)
			tmpp->start->ant -= (lem->nb_ants % lem->nb_path);
		i--;
		tmpp->ant_min = tmpp->start->ant;
		tmpp->start->visit = 1;
		tmpp = tmpp->next;
	}
}

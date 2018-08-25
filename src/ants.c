/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/25 18:28:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_one_line(t_lem *lem)
{
	t_path	*tmpp;
	t_link	*tmpl;

	tmpp = lem->path;
	while (tmpp)
	{
		tmpl = tmpp->start->next;
		while (tmpl && tmpl->ant != 0)
		{
			ft_printf("L%d-%s ", tmpl->ant, tmpl->room_link->name);
			tmpl->ant++;
			tmpl = tmpl->next;
		}
		tmpp = tmpp->next;
	}
}

static void	get_count_path(t_lem *lem)
{
	t_path	*tmpp;

	tmpp = lem->path;
	while (tmpp)
	{
		lem->nb_path++;
		tmpp = tmpp->next;
	}
}

static void	assign_ant_first_room(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	i = lem->nb_path - 1;
	tmpp = lem->path;
	tmpp->start->next->ant = 1;
	tmpp = tmpp->next;
	while (tmpp)
	{
		if (!(lem->nb_ants % lem->nb_path))
			tmpp->start->next->ant = lem->nb_ants + 1 - (i * (lem->nb_ants / lem->nb_path));
		i--;
		tmpp = tmpp->next;
	}
}

void		print_ants(void)
{
	t_lem	*lem;

	lem = get_lem();
	get_count_path(lem);
	assign_ant_first_room(lem);
	print_one_line(lem);
}
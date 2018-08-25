/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/25 21:34:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// need to print from end to start to free previous room before sending new ant

static int	print_one_line(t_lem *lem)
{
	t_path	*tmpp;
	t_link	*tmpl;

	tmpp = lem->path;
	while (tmpp)
	{
		tmpl = tmpp->start->next;
		while (tmpl && tmpl->ant)
		{
			ft_printf("L%u-%s ", tmpl->ant, tmpl->room_link->name);
			tmpl->ant++;
			if (tmpl->room_link->end && tmpl->ant > lem->nb_ants)
				return (0);
			tmpl = tmpl->next;
		}
		if (tmpl)
			tmpl->ant++;
		tmpp = tmpp->next;
	}
	return (1);
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

/*
** assigns ant numbers to each path and the max ant they are handling
*/

static void	assign_first_max(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	i = lem->nb_path;
	tmpp = lem->path;
	while (tmpp)
	{
		if (!(lem->nb_ants % lem->nb_path))
		{
			tmpp->start->next->ant = lem->nb_ants + 1 - (i * (lem->nb_ants / lem->nb_path));
			tmpp->ant_max = lem->nb_ants + 1 - ((i - 1) * (lem->nb_ants / lem->nb_path));
		}
		if ((lem->nb_ants % lem->nb_path))
		{
		}
		i--;
		tmpp = tmpp->next;
	}
}

void		print_ants(void)
{
	t_lem	*lem;

	lem = get_lem();
	get_count_path(lem);
	assign_first_max(lem);
	while (print_one_line(lem))
		ft_printf("\n");
}
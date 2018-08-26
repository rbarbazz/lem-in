/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/26 18:14:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_last(t_lem *lem)
{
	t_path	*tmpp;

	tmpp = lem->path;
	while (tmpp)
	{
		if (!tmpp->done)
			return (0);
		tmpp = tmpp->next;
	}
	return (1);
}

static int	print_one_line(t_lem *lem)
{
	t_path	*tmpp;
	t_link	*tmpl;

	tmpp = lem->path;
	while (tmpp)
	{
		tmpl = tmpp->start;
		while (tmpl && tmpl->next)
			tmpl = tmpl->next;
		while (tmpl)
		{
			if (tmpl->ant && !tmpp->done)
				ft_printf("L%u-%s ", tmpl->ant, tmpl->room_link->name);
			if (tmpl->ant == tmpp->ant_max && tmpl->room_link->end)
				tmpp->done = 1;
			tmpl = tmpl->prev;
		}
		tmpp = tmpp->next;
	}
	ft_printf("\n");
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

void		print_ants(void)
{
	t_lem	*lem;

	lem = get_lem();
	get_count_path(lem);
	assign_first_ant(lem);
	assign_max_ant(lem);
	ft_printf("\n");
	while (print_one_line(lem) && !check_last(lem))
		move_ants(lem);
}

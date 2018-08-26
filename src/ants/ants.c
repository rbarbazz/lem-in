/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/26 16:35:56 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
			if (tmpl->ant)
				ft_printf("L%u-%s ", tmpl->ant, tmpl->room_link->name);
			if (tmpl->ant == lem->nb_ants && tmpl->room_link->end)
			 	return (0);
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
	while (print_one_line(lem))
		move_ants(lem);
	ft_printf("\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/26 12:42:50 by rbarbazz         ###   ########.fr       */
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
** assigns the max ant each path is handling
*/

static void	assign_max_ant(t_lem *lem)
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
		ft_printf("max->%u\n", tmpp->ant_max);
		tmpp = tmpp->next;
	}
}

/*
** assigns ant numbers to each path and the max ant they are handling
*/

static void	assign_first_ant(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	i = lem->nb_path;
	tmpp = lem->path;
	while (tmpp)
	{
		tmpp->start->next->ant = 1 + lem->nb_ants - (i * (lem->nb_ants / lem->nb_path));
		if ((lem->nb_ants % lem->nb_path) && i == lem->nb_path)
			tmpp->start->next->ant -= (lem->nb_ants % lem->nb_path);
		i--;
		ft_printf("first->%u\n", tmpp->start->next->ant);
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
	while (print_one_line(lem))
		ft_printf("\n");
}
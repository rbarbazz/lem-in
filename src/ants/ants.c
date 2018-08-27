/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:21:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/27 19:15:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** prints the ant-room combinaisons as long as they are ants in the paths
** if it finds a last ant into the end, marks path as done
** the nl int helps not printing space before newline
*/

static void	print_one_line(t_lem *lem, int *nl)
{
	t_path	*tmpp;
	t_link	*tmpl;

	tmpp = lem->path;
	while (tmpp && !tmpp->done)
	{
		tmpl = tmpp->start;
		while (tmpl && tmpl->next)
			tmpl = tmpl->next;
		while (tmpl)
		{
			if (tmpl->ant)
			{
				if (!*nl)
					ft_printf(" ");
				*nl = 0;
				ft_printf("L%u-%s", tmpl->ant, tmpl->room_link->name);
			}
			if (tmpl->ant == tmpp->ant_max && tmpl->room_link->end)
				tmpp->done = 1;
			tmpl = tmpl->prev;
		}
		tmpp = tmpp->next;
	}
	*nl = ft_printf("\n");
}

/*
** checks if all path have sent all their ants to the end
*/

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

static void	get_count_path(t_lem *lem)
{
	t_path	*tmpp;
	int		i;

	tmpp = lem->path;
	i = 0;
	while (tmpp)
	{
		i++;
		tmpp = tmpp->next;
	}
	lem->nb_path = i;
}

void		print_ants(void)
{
	t_lem		*lem;
	static int	nl = 1;

	lem = get_lem();
	get_count_path(lem);
	assign_first_ant(lem);
	assign_max_ant(lem);
	ft_printf("\n");
	while (!check_last(lem))
	{
		print_one_line(lem, &nl);
		move_ants(lem);
	}
}

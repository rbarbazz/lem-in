/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:13:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 18:35:28 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_path(void)
{
	t_lem	*lem;
	t_path	*tmpp;
	t_link	*tmpl;

	lem = get_lem();
	tmpp = lem->path;
	ft_printf("\n");
	while (tmpp)
	{
		ft_printf("%s -> ", lem->start->name);
		tmpl = tmpp->start;
		while (tmpl)
		{
			ft_printf("%s ", tmpl->room_link->name);
			tmpl = tmpl->next;
			if (tmpl)
			ft_printf("-> ");
		}
		ft_printf("-> %s", lem->end->name);
		ft_printf("\n");
		tmpp = tmpp->next;
	}
}

void	print_map(void)
{
	t_lem	*lem;
	t_map	*tmp;

	lem = get_lem();
	tmp = lem->full_map;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

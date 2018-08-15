/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:13:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/15 17:54:02 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(void)
{
	t_lem	*lem;
	t_room	*tmp;
	t_link	*tmp1;

	lem = get_lem();
	tmp = lem->room;
	tmp1 = lem->link;
	ft_printf("%u\n", lem->nb_ants);
	while (tmp)
	{
		if (tmp->start)
			ft_printf("##start\n");
		if (tmp->end)
			ft_printf("##end\n");
		ft_printf("%s %llu %llu\n", tmp->name, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	while (tmp1)
	{
		ft_printf("%s-%s\n", tmp1->link0, tmp1->link1);
		tmp1 = tmp1->next;
	}
}

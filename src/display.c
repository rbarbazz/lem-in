/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:13:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 14:07:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(void)
{
	t_lem	*lem;
	t_room	*tmp;

	lem = get_lem();
	tmp = lem->room;
	ft_printf("%u\n", lem->nb_ants);
	while (tmp)
	{
		if (tmp->start)
			ft_printf("##start\n");
		if (tmp->end)
			ft_printf("##end\n");
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

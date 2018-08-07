/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:13:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 02:01:22 by rbarbazz         ###   ########.fr       */
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
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

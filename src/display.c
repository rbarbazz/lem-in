/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 20:13:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/03 20:18:16 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(void)
{
	t_map	*tmp;
	t_lem	*lem;

	lem = get_lem();
	tmp = lem->map;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

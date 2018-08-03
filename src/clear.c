/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:49:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/03 16:49:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	free_map(t_map *map)
{
	t_map	*tmp;
	
	tmp = map;
	while (map)
	{
		tmp = map;
		map = map->next;
		ft_strdel(&tmp->line);
		ft_memdel((void**)&tmp);
	}
}

void		free_lem(void)
{
	t_lem	*lem;

	lem = get_lem();
	free_map(lem->map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:27:04 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/28 16:24:58 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** get nb of ants and check if value is a number, > 0 and < UINT_MAX
*/

static int	get_nb_ants(t_lem *lem)
{
	int					i;
	unsigned long long	res;

	i = 0;
	while (lem->map->line[i])
	{
		if (!ft_isdigit(lem->map->line[i]))
			return (1);
		i++;
	}
	if ((res = atoull(lem->map->line)) > UINT_MAX || !res)
		return (1);
	lem->nb_ants = (unsigned int)res;
	free_node_map(lem);
	return (0);
}

static void	get_start_end(t_lem *lem)
{
	t_room	*tmp;

	tmp = lem->room;
	while (tmp)
	{
		if (tmp->start)
			lem->start = tmp;
		if (tmp->end)
			lem->end = tmp;
		tmp = tmp->next;
	}
}

int			parse_map(void)
{
	t_lem	*lem;

	lem = get_lem();
	if (get_nb_ants(lem) || get_rooms(lem))
		return (1);
	get_start_end(lem);
	if (get_links(lem) < 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:27:04 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/06 19:41:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** get nb of ants and check if value is a number, > 0 and < UINT_MAX
*/

static int	get_nb_ants(void)
{
	t_lem				*lem;
	int					i;
	unsigned long long	res;

	lem = get_lem();
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
	return (0);
}

static int	get_rooms(void)
{
	t_lem	*lem;

	lem = get_lem();
	return (0);
}

int			parse_map(void)
{
	if (get_nb_ants() || get_rooms())
		return (1);
	return (0);
}
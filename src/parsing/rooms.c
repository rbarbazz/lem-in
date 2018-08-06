/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 01:09:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_room(char	**splited)
{
	int	i;

	i = 0;
	if (!splited[2] || splited[3])
		return (1);
	return (0);
}

int	get_rooms(t_lem	*lem)
{
	t_map	*tmp;
	int		ret;
	char	**splited;

	ret = 0;
	tmp = lem->map->next;
	while (tmp)
	{
		splited = strsplit_whitespace(tmp->line);
		if ((splited && splited[0] && !splited[1]) || (ret = check_room(splited)))
			break ;
		tmp = tmp->next;
	}
	strstr_free(splited);
	return (ret);
}
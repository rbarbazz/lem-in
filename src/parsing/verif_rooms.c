/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:47:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/15 13:22:38 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*remove_node(t_room *tmp, t_lem *lem)
{
	t_room	*new;

	ft_strdel(&tmp->name);
	if (!tmp->prev)
	{
		new = tmp->next;
		lem->room = new;
		ft_memdel((void**)&tmp);
		return (new);
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	new = tmp->prev;
	ft_memdel((void**)&tmp);
	return (new);
}

int				check_duplicate(char **splited)
{
	t_lem	*lem;
	t_room	*tmp;

	lem = get_lem();
	tmp = lem->room;
	while (tmp)
	{
		if (!ft_strcmp(splited[0], tmp->name))
		{
			strstr_free(splited);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
** check if exactly one start and one end are present
*/

int				check_start_end(t_lem *lem)
{
	t_room	*tmp;

	tmp = lem->room;
	while (tmp)
	{
		if (tmp->name[0] == '#' && (!tmp->next || tmp->next->name[0] == '#'))
			return (1);
		if (!ft_strcmp("##start", tmp->name) && (tmp->next->start = 1))
			lem->start++;
		if (!ft_strcmp("##end", tmp->name) && (tmp->next->end = 1))
			lem->end++;
		if (tmp->name[0] == '#')
			tmp = remove_node(tmp, lem);
		tmp = tmp->next;
	}
	if (lem->start != 1 || lem->end != 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/08 10:11:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_node(char *name, t_lem *lem)
{
	t_room	*new;
	t_room	*tmp;

	tmp = lem->room;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room*)ft_memalloc(sizeof(t_room))))
		return ;
	if (!lem->room)
		lem->room = new;
	else
		tmp->next = new;
	new->name = ft_strdup(name);
	new->start = 0;
	new->end = 0;
	new->next = NULL;
	new->prev = tmp;
}

static t_room	*remove_node(t_room *tmp, t_lem	*lem)
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

/*
** check if the room exists and is correctly formatted
*/

static int	check_room_syntax(char **splited)
{
	if (splited && splited[0] && !splited[1])
	{
		if (!ft_strcmp("##start", splited[0]) || !ft_strcmp("##end", splited[0]))
		{
			return (0);
		}
		strstr_free(splited);
		return (1);
	}
	if (!splited[2] || splited[3] || !is_number(splited[1]) ||\
	!is_number(splited[2]))
	{
		strstr_free(splited);
		return (2);
	}
	return (0);
}

/*
** check if one start and one end are present
*/

static int	check_start_end(t_lem *lem)
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

int			get_rooms(t_lem *lem)
{
	t_map	*tmp;
	char	**splited;

	tmp = lem->map;
	while (tmp)
	{
		if ((splited = strsplit_whitespace(tmp->line)) && check_room_syntax(splited) == 1)
			break ;
		if (check_room_syntax(splited) == 2)
			return (1);
		add_node(splited[0], lem);
		strstr_free(splited);
		tmp = tmp->next;
		free_node_map(lem);
	}
	if (check_start_end(lem))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 19:57:42 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	init_node(t_room *new)
{
	new->start = 0;
	new->end = 0;
	new->link = NULL;
	new->next = NULL;
	new->next_queue = NULL;
	new->parent = NULL;
	new->visit = 0;
}

static void	add_node(char **splited, t_lem *lem)
{
	t_room	*new;
	t_room	*tmp;

	tmp = lem->room;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room*)ft_memalloc(sizeof(t_room))))
	{
		free_lem();
		exit(1);
	}
	if (!lem->room)
		lem->room = new;
	else
		tmp->next = new;
	new->name = ft_strdup(splited[0]);
	new->prev = tmp;
	init_node(new);
}

/*
** check if the room exists and is correctly formatted
*/

static int	check_room_syntax(char **splited)
{
	if (!splited[0])
	{
		strstr_free(splited);
		return (1);
	}
	else if (!splited[1])
	{
		if (!ft_strcmp("##start", splited[0]) ||\
		!ft_strcmp("##end", splited[0]))
			return (3);
		return (2);
	}
	else if (!splited[2] || splited[3] || !is_number(splited[1]) ||\
	!is_number(splited[2]) || ft_strchr(splited[0], '-'))
	{
		strstr_free(splited);
		return (1);
	}
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

/*
** breaks when the last room with a matching syntax was found
*/

int			get_rooms(t_lem *lem)
{
	t_map	*tmp;
	char	**splited;

	tmp = lem->map;
	while (tmp)
	{
		if (!(splited = strsplit_whitespace(tmp->line)) ||\
		check_room_syntax(splited) == 1 || (!check_room_syntax(splited) &&\
		check_duplicate(splited)))
			return (1);
		if (check_room_syntax(splited) == 2)
		{
			strstr_free(splited);
			break ;
		}
		add_node(splited, lem);
		strstr_free(splited);
		tmp = tmp->next;
		free_node_map(lem);
	}
	if (check_start_end(lem))
		return (1);
	get_start_end(lem);
	return (0);
}

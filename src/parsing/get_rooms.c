/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/13 12:02:26 by rbarbazz         ###   ########.fr       */
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

/*
** check if the room exists and is correctly formatted
*/

static int	check_room_syntax(char **splited)
{
	if (splited && splited[0] && !splited[1])
	{
		if (!ft_strcmp("##start", splited[0]) ||\
		!ft_strcmp("##end", splited[0]))
			return (0);
		strstr_free(splited);
		return (1);
	}
	if (!splited[2] || splited[3] || !is_number(splited[1]) ||\
	!is_number(splited[2]))
	{
		ft_printf("dab");
		strstr_free(splited);
		return (2);
	}
	return (0);
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
		if ((splited = strsplit_whitespace(tmp->line)) &&\
		check_room_syntax(splited) == 1)
			break ;
		if (check_room_syntax(splited) == 2 || check_duplicate(splited))
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

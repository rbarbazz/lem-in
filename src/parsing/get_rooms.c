/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/28 20:16:40 by rbarbazz         ###   ########.fr       */
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
	if (!(new = (t_room*)ft_memalloc(sizeof(t_room))) ||\
	!(new->name = ft_strdup(splited[0])))
	{
		free_lem();
		exit(1);
	}
	if (!lem->room)
		lem->room = new;
	else
		tmp->next = new;
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

static int	check_non_print(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line && line[i])
	{
		if (!ft_isprint(line[i]))
			count++;
		i++;
	}
	return (count);
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
		check_duplicate(splited)) || check_bigl_spaces(tmp->line))
			return (1);
		if (check_room_syntax(splited) == 2)
		{
			strstr_free(splited);
			break ;
		}
		if (check_room_syntax(splited) != 3 && check_non_print(tmp->line) != 2)
			return (1);
		add_node(splited, lem);
		strstr_free(splited);
		tmp = tmp->next;
		free_node_map(lem);
	}
	if (check_start_end(lem))
		return (1);
	return (0);
}

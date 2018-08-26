/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:58:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/26 18:13:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** if link does not exist yet, adds room_link to room
*/

static void	add_link(t_room *room, t_room *room_link)
{
	t_link	*newl;
	t_link	*tmpl;

	tmpl = room->link;
	while (tmpl)
	{
		if (!ft_strcmp(room_link->name, tmpl->room_link->name))
			return ;
		tmpl = tmpl->next;
	}
	tmpl = room->link;
	while (tmpl && tmpl->next)
		tmpl = tmpl->next;
	if (!(newl = (t_link*)ft_memalloc(sizeof(t_link))))
	{
		free_lem();
		exit(1);
	}
	if (!room->link)
		room->link = newl;
	else
		tmpl->next = newl;
	init_link(newl, room_link, tmpl);
}

/*
** goes through the list of rooms to find the matching rooms
*/

static void	find_links(char **splited, t_lem *lem)
{
	t_room	*tmp;
	t_room	*tmp1;

	tmp = lem->room;
	tmp1 = lem->room;
	while (tmp && ft_strcmp(splited[0], tmp->name) != 0)
		tmp = tmp->next;
	while (tmp1 && ft_strcmp(splited[1], tmp1->name) != 0)
		tmp1 = tmp1->next;
	add_link(tmp, tmp1);
	add_link(tmp1, tmp);
}

/*
** check if both names match with known rooms
*/

static int	check_name(char **splited)
{
	t_lem	*lem;
	t_room	*tmp;
	int		match;

	match = 0;
	lem = get_lem();
	tmp = lem->room;
	while (tmp && splited && splited[0] && splited[1])
	{
		if (!ft_strcmp(tmp->name, splited[0]))
			match++;
		if (!ft_strcmp(tmp->name, splited[1]))
			match++;
		tmp = tmp->next;
	}
	return (match);
}

/*
** a '-' is a link so a map cannot have a '-' in its name
** making it impossible to have a case like 'keep-carry-on'
*/

static int	check_link(char *line)
{
	char	**splited;
	int		ret;
	int		count;

	ret = 0;
	count = count_char(line, '-');
	if (((splited = strsplit_whitespace(line)) && splited[1]))
		ret = 1;
	strstr_free(splited);
	if ((splited = ft_strsplit(line, '-')) && (!splited[1] || splited[2]))
		ret = 1;
	if (count != 1 || (!ret && check_name(splited) != 2))
		ret = 1;
	strstr_free(splited);
	return (ret);
}

/*
** returns the number of valid links found
*/

int			get_links(t_lem *lem)
{
	t_map	*tmp;
	int		ret;
	char	**splited;

	tmp = lem->map;
	ret = 0;
	while (tmp)
	{
		if (check_link(tmp->line))
			break ;
		splited = ft_strsplit(tmp->line, '-');
		find_links(splited, lem);
		strstr_free(splited);
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

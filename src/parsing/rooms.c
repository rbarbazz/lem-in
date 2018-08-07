/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:08:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 02:15:27 by rbarbazz         ###   ########.fr       */
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
	new->next = NULL;
}

static int	check_room(char **splited)
{
	if (!splited[2] || splited[3] || !is_number(splited[1]) ||\
	!is_number(splited[2]))
		return (1);
	return (0);
}

int			get_rooms(t_lem *lem)
{
	t_map	*tmp;
	int		ret;
	char	**splited;

	ret = 0;
	tmp = lem->map->next;
	while (tmp)
	{
		splited = strsplit_whitespace(tmp->line);
		if ((splited && splited[0] && !splited[1]) ||\
		(ret = check_room(splited)))
		{
			strstr_free(splited);
			break ;
		}
		add_node(splited[0], lem);
		strstr_free(splited);
		tmp = tmp->next;
	}
	return (ret);
}

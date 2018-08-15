/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:27:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/15 15:21:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		add_node(char *line)
{
	t_map	*new;
	t_map	*tmp;
	t_lem	*lem;

	lem = get_lem();
	tmp = lem->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
	{
		free_lem();
		exit (1);
	}
	if (!lem->map)
		lem->map = new;
	else
		tmp->next = new;
	new->line = ft_strdup(line);
	new->next = NULL;
}

static int		check_bigl_spaces(char *line)
{
	if (line && line[0] && (line[0] == 'L' || !ft_isprint(line[0])))
		return (1);
	return (0);
}

/*
** doesn't store comments
*/

static int		check_comment(char *line)
{
	if (!ft_strcmp("##start", line))
		return (0);
	else if (!ft_strcmp("##end", line))
		return (0);
	else if (line[0] == '#')
		return (1);
	return (0);
}

int				store_map(void)
{
	t_lem	*lem;
	char	*line;

	lem = get_lem();
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (check_bigl_spaces(line))
			return (1);
		if (!check_comment(line))
			add_node(line);
		ft_strdel(&line);
	}
	if (!lem->map)
		return (1);
	return (0);
}

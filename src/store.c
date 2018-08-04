/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:27:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/04 18:55:50 by rbarbazz         ###   ########.fr       */
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
		return ;
	if (!lem->map)
		lem->map = new;
	else
		tmp->next = new;
	new->line = ft_strdup(line);
	new->next = NULL;
}

/*
** doesn't store comments
*/

static int		check_comment(char *line)
{
	if (ft_strcmp("##start", line) == 1)
		return (0);
	else if (ft_strcmp("##end", line) == 1)
		return (0);
	else if (line[0] == '#')
		return (1);
	return (0);
}

/*
** stop storing if an empty line is found
*/

static int		check_empty(char *line)
{
	int	print;
	int	i;

	i = 0;
	print = 0;
	if (!line || !line[0])
		return (1);
	while (line[i])
	{
		if (ft_isprint(line[i]))
			print = 1;
		i++;
	}
	if (!print)
		return (1);
	return (0);
}

int				store_map(void)
{
	t_lem	*lem;
	int		empty;
	char	*line;

	lem = get_lem();
	empty = 0;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (check_empty(line))
			empty = 1;
		if (!check_comment(line) && !empty)
			add_node(line);
		ft_strdel(&line);
	}
	if (!lem->map)
		return (1);
	return (0);
}

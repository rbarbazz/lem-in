/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:58:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/16 12:53:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_link(char **splited, t_lem *lem)
{
	char	 **tmp;
	t_lem	*dab;
	dab = lem;
	tmp = splited;
}

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

	ret = 0;
	if ((splited = strsplit_whitespace(line)) && splited[1])
		ret = 1;
	strstr_free(splited);
	if ((splited = ft_strsplit(line, '-')) && (!splited[1] || splited[2]))
		ret = 1;
	if (!ret && check_name(splited) != 2)
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
		add_link(splited, lem);
		strstr_free(splited);
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:58:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/08 10:33:00 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_link_syntax(char *line)
{
	char	**splited;
	int		ret;

	ret = 0;
	if ((splited = strsplit_whitespace(line)) && splited[1])
		ret = 1;
	strstr_free(splited);
	if ((splited = ft_strsplit(line, '-')) && (!splited[1] || splited[2]))
		ret = 1;
	strstr_free(splited);
	//to add check if both rooms exist and add node function
	return (ret);
}

void		get_links(t_lem *lem)
{
	t_map	*tmp;

	tmp = lem->map;
	while (tmp)
	{
		if (check_link_syntax(tmp->line))
			break ;
		tmp = tmp->next;
	}
}
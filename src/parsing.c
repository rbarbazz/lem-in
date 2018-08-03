/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:27:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/03 18:22:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_comment(char *line)
{
	if (ft_strcmp("##start", line) == 1)
		return (0);
	else if (ft_strcmp("##end", line) == 1)
		return (0);
	else if (line[0] == '#')
		return (1);
	return (0);
}

int	store_map(void)
{
	t_lem	*lem;
	char	*line;

	lem = get_lem();
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!check_comment(line))
		{}// ajouter en liste
	}
	ft_printf("%s\n", lem->map);
	return (0);
}

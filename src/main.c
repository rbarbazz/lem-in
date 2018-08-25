/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/25 17:00:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lem		*get_lem(void)
{
	static t_lem	lem;

	return (&lem);
}

void		get_shortest_size(t_lem *lem)
{
	t_path	*tmpp;
	int		shortest;

	tmpp = lem->path;
	shortest = tmpp->size;
	tmpp = tmpp->next;
	while (tmpp)
	{
		if (tmpp->size < shortest)
			shortest = tmpp->size;
		tmpp = tmpp->next;
	}
	lem->shortest = shortest;
}

static void	init_lem(void)
{
	t_lem	*lem;

	lem = get_lem();
	lem->start = NULL;
	lem->end = NULL;
	lem->map = NULL;
	lem->full_map = NULL;
	lem->room = NULL;
	lem->queue = NULL;
	lem->path = NULL;
	lem->shortest = 0;
	lem->nb_path = 0;
}

int			main(int argc, char **argv)
{
	if (argc != 1 || argv[1])
		return (ft_printf("ERROR\n"));
	init_lem();
	if (store_map() || parse_map() || algo())
	{
		free_lem();
		return (ft_printf("ERROR\n"));
	}
	print_map();
	save_path();
	print_path();
	print_ants();
	free_lem();
	return (0);
}

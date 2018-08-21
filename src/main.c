/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/21 10:41:14 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lem		*get_lem(void)
{
	static t_lem	lem;

	return (&lem);
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
	free_lem();
	return (0);
}

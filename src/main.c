/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:22:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 02:09:36 by rbarbazz         ###   ########.fr       */
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
	lem->map = NULL;
	lem->room = NULL;
}

int			main(void)
{
	init_lem();
	if (store_map() || parse_map())
	{
		free_lem();
		return (ft_printf("ERROR"));
	}
	print_map();
	free_lem();
	return (0);
}

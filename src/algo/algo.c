/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:11:55 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/15 17:34:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	find_path(t_link *link)
{
	t_link	*tmp;

	tmp = link;
	return (0);
}

int			algo(void)
{
	t_lem	*lem;

	lem = get_lem();
	if (find_path(lem->link))
		return (1);
	return (0);
}

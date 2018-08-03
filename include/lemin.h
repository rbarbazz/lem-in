/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/03 18:24:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_lem
{
	t_map			*map;
}					t_lem;

t_lem				*get_lem(void);

/*
** parsing
*/

int					store_map(void);

/*
** clearing memory
*/

void				free_lem(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/07 02:12:37 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct			s_room
{
	char				*name;
	struct s_room		*next;
}						t_room;

typedef struct			s_map
{
	char				*line;
	struct s_map		*next;
}						t_map;

typedef struct			s_lem
{
	t_map				*map;
	unsigned int		nb_ants;
	t_room				*room;
}						t_lem;

t_lem					*get_lem(void);

/*
** parsing
*/

int						store_map(void);
int						parse_map(void);
int						get_rooms(t_lem	*lem);

/*
** display
*/

void					print_map(void);

/*
** clearing memory
*/

void					free_lem(void);

#endif

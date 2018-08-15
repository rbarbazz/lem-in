/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/15 14:13:31 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct			s_link
{
	char				*link0;
	char				*link1;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	struct s_room		*prev;
	struct s_room		*next;
}						t_room;

typedef struct			s_map
{
	char				*line;
	struct s_map		*next;
}						t_map;

typedef struct			s_lem
{
	int					start;
	int					end;
	t_map				*map;
	unsigned int		nb_ants;
	t_room				*room;
	t_link				*link;
}						t_lem;

t_lem					*get_lem(void);

/*
** parsing
*/

int						store_map(void);
int						parse_map(void);
int						get_rooms(t_lem	*lem);
int						check_start_end(t_lem *lem);
int						check_duplicate(char **splited);
int						get_links(t_lem *lem);

/*
** algo
*/

int						algo(void);

/*
** display
*/

void					print_map(void);

/*
** clearing memory
*/

void					free_lem(void);
void					free_node_map(t_lem *lem);

#endif

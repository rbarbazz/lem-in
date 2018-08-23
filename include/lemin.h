/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/23 18:16:09 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct			s_link
{
	struct s_room		*room_link;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	char				*name;
	struct s_room		*prev;
	struct s_room		*next;
	int					start;
	int					end;
	t_link				*link;
	struct s_room		*next_queue;
	t_link				*parent;
	int					visit;
}						t_room;

typedef struct			s_path
{
	t_link				*start;
	int					size;
	struct s_path		*prev;
	struct s_path		*next;
}						t_path;

typedef struct			s_map
{
	char				*line;
	struct s_map		*next;
}						t_map;

typedef struct			s_lem
{
	t_map				*full_map;
	t_map				*map;
	t_room				*start;
	t_room				*end;
	unsigned int		nb_ants;
	t_room				*room;
	t_room				*queue;
	t_path				*path;
	int					shortest;
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
void					get_shortest_size(t_lem *lem);

/*
** algo
*/

int						algo(void);
void					remove_from_queue(t_lem *lem);
void					add_to_queue(t_room *node, t_room *parent);
void					add_parent(t_room *room, t_room *parent);

/*
** display
*/

void					print_map(void);
void					save_path(void);
void					print_path(void);
void					clear_visit(t_room *room);

/*
** clearing memory
*/

void					free_lem(void);
void					free_node_map(t_lem *lem);
void					clear_one_path(t_path *path);

#endif

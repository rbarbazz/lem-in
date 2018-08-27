/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/27 11:54:30 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct		s_link
{
	struct s_room	*room_link;
	unsigned int	ant;
	int				visit;
	struct s_link	*prev;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	t_link			*link;
	t_link			*parent;
	int				visit;
	struct s_room	*next_queue;
	struct s_room	*prev;
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	t_link			*start;
	int				size;
	unsigned int	ant_min;
	unsigned int	ant_max;
	int				done;
	struct s_path	*prev;
	struct s_path	*next;
}					t_path;

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_lem
{
	t_map			*full_map;
	t_map			*map;
	t_room			*start;
	t_room			*end;
	unsigned int	nb_ants;
	t_room			*room;
	t_room			*queue;
	t_path			*path;
	int				shortest;
	int				nb_path;
}					t_lem;

t_lem				*get_lem(void);

/*
** parsing
*/

int					store_map(void);
int					parse_map(void);
int					get_rooms(t_lem	*lem);
int					check_start_end(t_lem *lem);
int					check_duplicate(char **splited);
int					get_links(t_lem *lem);
void				get_shortest_size(t_lem *lem);

/*
** algo
*/

int					algo(void);
void				remove_from_queue(t_lem *lem);
void				add_to_queue(t_room *node, t_room *parent);
void				add_parent(t_room *room, t_room *parent);

/*
** display
*/

void				print_map(void);
void				save_path(void);
void				print_path(void);
void				print_ants(void);
void				assign_first_ant(t_lem *lem);
void				assign_max_ant(t_lem *lem);
void				move_ants(t_lem *lem);

/*
** clear
*/

void				free_lem(void);
void				free_node_map(t_lem *lem);
void				free_path(t_path *path);
void				clear_one_path(t_path *path);
void				clear_visit(t_room *room);

/*
** init
*/

void				init_path(t_path *newp, t_path *tmpp);
void				init_link(t_link *newl, t_room *room_link, t_link *tmpl);

#endif

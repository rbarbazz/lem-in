/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:00:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/01 00:58:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_room
{
	int				num;
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem
{
	int				nb_ants;
	t_room			*room;
}					t_lem;

#endif
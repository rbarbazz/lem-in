/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcatchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:02:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/03 16:33:00 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends a char c at the end of the previously malloced char* s1
*/

char	*strcatchar(char *s1, char const c)
{
	char	add[2];
	char	*result;

	add[0] = c;
	add[1] = '\0';
	result = ft_strjoin(s1, add);
	ft_strdel(&s1);
	return (result);
}

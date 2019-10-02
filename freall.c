/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:48:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 18:24:16 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tet_next(t_fillit *start)
{
	int			i;
	t_fillit	*buf;

	while (start)
	{
		buf = start->next;
		i = -1;
		while (++i < start->height - 1)
			ft_strdel(&start->tet[i]);
		ft_strdel(&start->grid);
		free(start);
		start = buf;
	}
	start = NULL;
}

int		free_error(t_fillit *list)
{
	t_fillit *sled;

	while (list)
	{
		sled = list;
		list = list->next;
		ft_strdel(&list->grid);
		free(sled);
	}
	list = NULL;
	return (1);
}

void	free_map(char **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_strdel(&map[i]);
	map = NULL;
}

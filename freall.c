/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:48:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/29 20:55:57 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_tet_next(fillit *start)
{
	int i;
	fillit *buf;
	
	while (start)
	{
		buf = start->next;
		i = -1;
		while (start->tet[++i])
			ft_strdel(&start->tet[i]);
		ft_strdel(&start->grid);
		free(start);
		start = buf;
	}
	start = NULL;
}

void	free_tet_back(fillit *list)
{
	fillit	*start;
	fillit	*buf;
	int		i;

	start = list;
	list = (list->prev ? list->prev : list);
	while (list->prev)
	{
		buf = list->prev;
		i = -1;
		while (list->tet[++i])
			ft_strdel(&list->tet[i]);
		ft_strdel(&list->grid);
		free(list);
		list = buf;
	}
	list = start;
	free_tet_next(list);
}

int		free_error(fillit *list)
{
	fillit *sled;

	while (list)
	{
		sled = list->next;
		ft_strdel(&list->grid);
		free(list);
		list = sled;
	}
	list = NULL;
	return (1);
}

void	free_map_back(mapl *map)
{
	mapl	*start;
	mapl	*buf;
	int		i;

	start = map;
	i = -1;
	while (map->map[++i])
		ft_strdel(&map->map[i]);
	map = (map->prev ? map->prev : map);
	while (map->prev)
	{
		buf = map->prev;
		free(map);
		map = buf;
	}
	map = start;
	while (map)
	{
		buf = map->next;
		free(map);
		map = buf;
	}
	map = NULL;
}

void	free_map_next(mapl *map)
{
	mapl *start;
	mapl *buf;

	start = map->prev;
	while (map)
	{
		buf = map->next;
		free(map);
		map = buf;
	}
	map = start;
	map->next = NULL;
}

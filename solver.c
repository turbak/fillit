/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/26 21:04:50 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

mapl 	*increase(mapl *maps)
{
	int size;
	mapl *head;
	mapl *sled;
	int i;
	
	head = maps;
	size = maps->map_size + 1;
	while (maps)
	{
		i = 0;
		sled = maps->next;
		while (maps->map[i])
		{
			ft_strdel(&maps->map[i]);
			i++;
		}
		maps = sled;
	}
	maps = malloc(sizeof(mapl));
	maps = head;
	maps->prev = NULL;
	maps->map = create_map(size);
	maps->map_size = size;
	return (maps);
}

int	try_tet(fillit *list, mapl *maps, int m, int n)
{
	int i;
	int j;

	i = 0;
	while (i < list->height)
	{
		if (i + m >= maps->map_size)
			return (0);
		j = 0;
		while (j < list->width)
		{
			if (j + n >= maps->map_size || (list->tet[i][j] != '.' && maps->map[i + m][j + n] != '.'))
				return(0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < list->height)
	{
		j = 0;
		while (j < list->width)
		{
			if ((list->tet[i][j] != '.' && maps->map[i + m][j + n] == '.'))
				maps->map[i + m][j + n] = list->tet[i][j];
			j++;
		}
		i++;
	}
	maps->next = malloc(sizeof(mapl));
	maps->next->map = maps->map;
	maps->next->prev = maps;
	maps->next->map_size = maps->map_size;
	maps->next->pos_i = 0;
	maps->next->pos_j = 0;
	return (1);
}

char	**create_map(int map_size)
{
	int i;
	char **map;

	i = 0;
	map = (char**)ft_memalloc(sizeof(char *) * map_size + 1);
	while (i < map_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * map_size + 1);
		memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

int		starting_size(fillit *list)
{
	int	counter;
	fillit *head;
	
	head = list;
	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	list = head;
	return (counter);
}

mapl	*solver(fillit *list, mapl *map, fillit *list_head, mapl *maps_head)
{
	int		i;
	int		j;
	int 	x;


	if (list)
	{
		i = map->pos_i;
		while (i < map->map_size)
		{
			j = (map->pos_j == 0 && map->pos_i == 0 ? 0 : map->pos_j + 1);
			while (j < map->map_size)
			{
				if (try_tet(list, map, i, j) /*&& ((i == 0 && j == 0) ? 1 : (i != map->pos_i || i != map->pos_j))*/)
				{
					map->pos_i = i;
					map->pos_j = j;
					return (solver(list->next, map->next, list_head, maps_head));
				}
				j++;
			}
			i++;
		}
		if (map->prev)
		{
			x = 0;
			while (map->prev->map[x])
			{
				ft_strset(map->prev->map[x], list->prev->c, '.');
				x++;
			}
			return (solver(list->prev, map->prev, list_head, maps_head));
		}
		else
		{
			map = increase(maps_head);
			return (solver(list_head, map, list_head, maps_head));
		}	
	}
	return (map);
}

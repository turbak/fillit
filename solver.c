/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/24 23:49:49 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solver(fillit *list)
{
	int count;
	int i;
	mapl *maps;

	maps->map_size = ft_sqrt(starting_size(list) * 4);
	maps->map = create_map(maps->map_size);
	
}

void	try_tet(fillit *list)
{
	
}

char	**create_map(int map_size)
{
	int i;
	char **map;

	i = 0;
	map = (char**)ft_mamalloc(sizeof(char *) * map_size + 1);
	while (i < map_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * map_size + 1);
		i++;
	}
	return (map);
}

int		starting_size(fillit *list)
{
	int	counter;
	fillit *head;
	
	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	list = head;
	return (counter);
}
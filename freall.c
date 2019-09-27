/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:48:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/27 20:53:31 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void	free_tet(fillit *list)
{
	fillit *sled;
	int i;

	while (list)
	{
		sled = list->next;
		i = 0;
		if (list->tet)
		{
			while (list->tet[i])
			{
				ft_strdel(&list->tet[i]);
				i++;
			}
		}
		if (list->grid)
			ft_strdel(&list->grid);
		free(list);
		list = NULL;
		list = sled;
	}
	list = NULL;
}

void	free_map(mapl *maps)
{
	int i;
	mapl *sled;

	i = 0;
	while (maps->map[i])
	{
		ft_strdel(&maps->map[i]);
		i++;
	}
	while (maps)
	{
		sled = maps->next;
		free(maps);
		maps = NULL;
		maps = sled;
	}
	maps = NULL;
}

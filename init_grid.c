/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:34:58 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 21:21:10 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*init_grid(void)
{
	t_fillit *ret;

	ret = malloc(sizeof(t_fillit));
	ret->grid = (char *)ft_memalloc(sizeof(char *) * 21);
	ret->next = NULL;
	if (!ret)
		return (NULL);
	return (ret);
}

char		**remove_dots(char **tet, int h, int width)
{
	int		i;
	int		j;
	int		k;
	char	**tm;

	i = 0;
	tm = (char **)malloc(sizeof(char*) * h);
	k = 0;
	j = 0;
	while (i < h)
	{
		tm[i] = (char *)ft_memalloc(sizeof(char) * width + 1);
		i++;
	}
	i = 0;
	while (tet[i][j])
	{
		if (tet[i][j] == '.' && tet[i + (2 <= h ? 1 : 0)][j] == '.' &&
		tet[i + (3 <= h ? 2 : 0)][j] == '.' && tet[i + (4 <= h ? 3 : 0)][j] == '.')
			j++;
		else
		{
			tm[i][k] = tet[i][j];
			tm[i + (2 <= h ? 1 : 0)][k] = tet[i + (2 <= h ? 1 : 0)][j];
			tm[i + (3 <= h ? 2 : 0)][k] = tet[i + (3 <= h ? 2 : 0)][j];
			tm[i + (4 <= h ? 3 : 0)][k] = tet[i + (4 <= h ? 3 : 0)][j];
			k++;
			j++;
		}
	}
	return (tm);
}

void		change_chars(t_fillit *list)
{
	t_fillit	*head;
	int			i;
	char		*tm;
	char		**temp;

	head = list;
	while (list)
	{
		i = 0;
		list->tet = (char**)malloc(sizeof(char*) * list->height);
		while (i < list->height)
		{
			list->tet[i] = (char*)ft_memalloc(sizeof(char) * 5);
			i++;
		}
		i = 0;
		tm = LG;
		while (*LG)
		{
			if (!(ft_strncmp(LG, "....\n", 4)))
				LG += 5;
			else
			{
				ft_strncpy(list->tet[i], LG, 4);
				LG += 5;
				i++;
			}
		}
		LG = tm;
		temp = remove_dots(list->tet, list->height, list->width);
		i = -1;
		while (++i < list->height)
			ft_strdel(&list->tet[i]);
		free(list->tet);
		list->tet = temp;
		list = list->next;
	}
	fill_chars(head);
	list = head;
}

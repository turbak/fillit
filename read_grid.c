/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:45:22 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 21:23:01 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*read_grid(int fd)
{
	t_fillit	*list;
	char		*line;
	int			i;
	t_fillit	*head;
	char		*tmp;

	i = 0;
	list = init_grid();
	head = list;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		while (*line)
		{
			LG[i] = *line;
			line++;
			i++;
		}
		if (i < 20)
			LG[i++] = '\n';
		else
		{
			if (!(validate(LG, list)))
			{
				ft_strdel(&tmp);
				CHECKRETURN(free_error(head), 0);
			}
			list->next = init_grid();
			list = list->next;
			i = 0;
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
	if (!(validate(LG, list)))
		CHECKRETURN(free_error(head), 0);
	change_chars(head);
	return (head);
}

int		count_ne(char *str)
{
	int i;
	int count;
	int fill;

	i = -1;
	fill = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			fill++;
			if (str[i + 1] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
		}
		if (fill == 4 && count < 6)
			return (0);
	}
	return (1);
}

int		validate(char *str, t_fillit *list)
{
	int row;
	int symb;
	int dot;
	int fill;
	int col;

	col = 0;
	symb = 0;
	dot = 0;
	fill = 0;
	row = 0;
	while (str[symb])
	{
		if (str[symb] != '\n')
			row++;
		else if (str[symb] == '\n')
		{
			if (row != 4)
				return (0);
			row = 0;
			col++;
		}
		if (str[symb] == '.')
			dot++;
		else if (str[symb] == '#')
			fill++;
		symb++;
	}
	if (col != 4 || dot + fill != symb - 4 || dot != 12 ||
	fill != 4 || !validate_piece(list) || !(count_ne(str)))
		return (0);
	return (1);
}

int		validate_piece(t_fillit *list)
{
	int i;
	int height;
	int flag;

	flag = 0;
	height = 0;
	i = -1;
	list->width = 0;
	while (LG[++i])
	{
		if (LG[i] == '#')
		{
			if ((LG[i + 5] == '#' || LG[i] == '#') && LG[i - 5] != '#')
				++list->width;
			CHECKRETURN((!(LG[i - 1] == '#' || LG[i + 1] == '#' ||
			LG[i - 5] == '#' || LG[i + 5] == '#')), 0);
			if (flag == 0)
			{
				flag = 1;
				height = i;
			}
			list->height = i / 5 - height / 5 + 1;
		}
	}
	return (1);
}

void	fill_chars(t_fillit *list)
{
	int			i;
	t_fillit	*head;
	char		c;

	head = list;
	c = 'A';
	while (list)
	{
		i = 0;
		while (i < list->height)
		{
			ft_strset(list->tet[i], '#', c);
			i++;
		}
		list->c = c;
		c++;
		list = list->next;
	}
	list = head;
}

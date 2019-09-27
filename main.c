/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/27 15:22:35 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	mapl	*maps;
	fillit	*list;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	list = read_grid(fd);
	if (list == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	maps = malloc(sizeof(mapl));
	maps->map_size = ft_sqrt(starting_size(list) * 4);
	maps->pos_i = 0;
	maps->pos_j = 0;
	maps->map = create_map(maps->map_size);
	maps = solver(list, maps, list, maps);
	write_grid(list, maps);
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:50 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/25 17:43:11 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef struct		g_list
{
	char			*grid;
	char			**tet;
	int				height;
	int				width;
	struct	g_list	*next;
}					fillit;

typedef struct		map_l
{
	char			**map;
	int				map_size;

	struct	map_l	*next;
}					mapl;

int					validate_piece(fillit *list);
int 				validate(char *str, fillit *list);
void				write_grid(fillit *list, mapl *maps);
fillit				*read_grid(int fd);
fillit				*init_grid(void);
void				change_chars(fillit *list);
void				fill_chars(fillit *list);
char				**remove_dots(char **tet, int height, int width);
char				**create_map(int map_size);
int					starting_size(fillit *list);
mapl				*solver(fillit *list, mapl *map, fillit *list_head, mapl *maps_head);
int					valid_tet(char **map, char c);
int					try_tet(fillit *list, mapl *maps, int m, int n);

#endif

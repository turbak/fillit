/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:34:58 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 17:59:48 by cauranus         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:03 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/10 14:38:46 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_it_one(t_map *map, int x, int y)
{
	while (++y < map->y_max)
	{
		x = -1;
		while (map->p[y][++x])
		{
			if (x >= map->x_max)
				break ;
			else if ((map->p[0][x] != '1' || map->p[map->y_max - 1][x] != '1')
				&& x != map->x_max)
				exit(ft_fd_printf(2, "%sTop Or Bottom\nline ->%s",
						ERROR_MAP_NOT_CLOSED, map->p[y]) * 0 + 1);
			is_it_two(map, x, y);
		}
		if (map->p[y][0] != '1' || map->p[y][map->x_max - 1] != '1')
			exit(ft_fd_printf(2, "%sSides\n%s", ERROR_MAP_NOT_CLOSED) * 0
				+ 1);
	}
	map->y--;
}

void	freewilly(t_map *map, int y)
{
	while (y > 0)
		free(map->p[y--]);
	free(map->p);
}

void	is_it_two(t_map *map, int x, int y)
{
	if (!ft_strchr("10CEPG", map->p[y][x]))
	{
		freewilly(map, map->y);
		exit(ft_fd_printf(2, "%s", ERROR_MAP_OBJECTS) * 0 + 1);
	}
	else if (y > map->y_max || x > map->x_max)
		exit(ft_fd_printf(2, "%s", ERROR_MAP_SIZE) * 0 + 1);
}

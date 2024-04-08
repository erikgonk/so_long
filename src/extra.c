/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:03 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/08 14:19:02 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_it_one(t_map *map)
{
	int		x;
	int		y;

	y = -1;	
	while (++y < map->y_max)
	{
		x = -1;
		while (map->p[y][++x])
		{
			if (x >= map->x_max)
				break ;
			if ((map->p[0][x] != '1' || map->p[map->y_max - 1][x] != '1') && x != map->x_max)
			{
				printf("x -> %d\ny -> %d\n%c\n%c\n%s", x, map->y_max, map->p[0][x], map->p[map->y_max - 1][x], map->p[0]);
				exit(ft_fd_printf(2, "%s Arriba O Abajo\n", ERROR_MAP_NOT_CLOSED) * 0 + 1);
			}
			if (!ft_strchr("10CEPG", map->p[y][x]))
			{
				freewilly(map, map->y);
				exit(ft_fd_printf(2, "%s", ERROR_MAP_OBJECTS) * 0 + 1);
			}
			if (y > map->y_max || x > map->x_max)
				exit(ft_fd_printf(2, "%s", ERROR_MAP_SIZE) * 0 + 1);
		}
		if (map->p[y][0] != '1' || map->p[y][map->x_max - 1] != '1')
		{
			freewilly(map, map->y_max);
			printf("y -> %d\n", y);
			exit(ft_fd_printf(2, "%sPor Los Lados\n", ERROR_MAP_NOT_CLOSED) * 0 + 1);
		}
	}
	map->y--;
}

void	freewilly(t_map *map, int y)
{
	while (y > 0)
		free(map->p[y--]);
	free(map->p);
}
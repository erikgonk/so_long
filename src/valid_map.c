/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:29:32 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/04 18:28:52 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_file(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '.' && name[i])
		i++;
	if (name[i + 4])
		return (0);
	if (name[i] == '.' && name[i + 1] == 'b' &&
			name[i + 2] == 'e' && name[i + 3] == 'r')
		return (1);
	return (0);
}

void	save_line(t_map *map, int fd)
{
	char            *tmp;

	map->p = malloc(sizeof (t_map));
	if (!map->p)
		exit(ft_fd_printf(2, "ERROR MALLOC\n") * 0 + 1);
	while (42 > 0)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map->p[map->y_max] = ft_strdup(tmp);
		free (tmp);
		if (!map->p[map->y_max])
			exit (1);
		if (map->p[map->y_max][0] == '\n')
			exit(ft_fd_printf(2, "%s", ERROR_EMPTY_MAP) * 0 + 1);
		if (!map->p[map->y_max++])
			break ;
	}
	// int a = -1;
	// while (map->p[++a])
	// 	printf("%s\n", map->p[a]);
	parsing(map);
}

void	parsing(t_map *map)
{
	map->y = -1;
	while (++map->y < map->y_max)
	{
		map->x_max = 0;
		while (map->p[map->y][map->x_max] && map->p[map->y][map->x_max] != '\n')
		{
			map->c_count += (map->p[map->y][map->x_max] == 'C');
			map->p_count += (map->p[map->y][map->x_max] == 'P');
			map->e_count += (map->p[map->y][map->x_max] == 'E');
			map->g_count += (map->p[map->y][map->x_max] == 'G');
			map->x_max++;
		}
	}
	map->y--;
	if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1 ||
			map->g_count < 1)
		exit(ft_fd_printf(2, "%s", ERROR_ADD_REMOVE_OBJECTS) * 0 + 1);
	is_it_one(map);
}

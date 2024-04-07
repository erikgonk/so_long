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
	if (name[i] == '.' && name[i + 1] == 'b' &&
			name[i + 2] == 'e' && name[i + 3] == 'r')
		return (1);
	return (0);
}

void	save_line(t_map *map, int fd)
{
	char		*tmp;

	map->p = malloc(sizeof (t_map));
	map->y_max = -1;
	while (-42 < ++map->y_max)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map->p[map->y_max] = ft_strdup(tmp);
		if (!map->p[map->y_max])
			exit (1);
		free(tmp);
		printf("%s", map->p[map->y_max]);
		if (!map->p[map->y_max])
			break ;
		else if (map->p[map->y_max][0] == '\n')
			exit(ft_fd_printf(2, "%s", ERROR_EMPTY_MAP) * 0 + 1);
	}
	parsing(map);
}

void	freewilly(t_map *map, int y)
{
	while (map->p[y] && map->p[y][0])
		free(map->p[y--]);
	free(map->p);
}

void	parsing(t_map *map)
{
	map->y = 0;
	while (map->p[map->y])
	{
		map->x = 0;
		while (map->p[map->y][map->x] != '\n' && map->p[map->y][map->x])
		{
			if (!ft_strchr("10CEPG", map->p[map->y][map->x]))
			{
				freewilly(map, map->y);
				exit(ft_fd_printf(2, "%s", ERROR_MAP_OBJECTS) * 0 + 1);
			}
			map->c_count += (map->p[map->y][map->x] == 'C');
			map->p_count += (map->p[map->y][map->x] == 'P');
			map->e_count += (map->p[map->y][map->x] == 'E');
			map->g_count += (map->p[map->y][map->x] == 'G');
			map->x++;
		}
		printf("%c\n", map->p[map->y][map->x]);
		check_x(map);
		if (map->y > map->y_max || map->x > map->x_max)
			exit(ft_fd_printf(2, "%s", ERROR_SIZE) * 0 + 1);
		map->y++;
	}
	if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1 ||
			map->g_count < 1)
	{
		exit(ft_fd_printf(2, "%d\n%d\n%d\n%s", map->p_count, map->e_count, map->c_count, map->g_count, ERROR_ADD_REMOVE_OBJECTS) * 0 + 1);
		freewilly(map, map->y);
	}
}

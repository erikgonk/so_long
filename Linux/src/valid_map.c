/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:29:32 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/12 16:39:06 by erigonza         ###   ########.fr       */
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
	if (name[i] == '.' && name[i + 1] == 'b' && name[i + 2] == 'e')
		return (1);
	else if (name[i + 3] == 'r')
		return (1);
	return (0);
}

static char	*ft_chrjoin(char *s1, char const s2)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		exit(ft_fd_printf(2, "ERROR\nMALLOC\n") * 0 + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	str[i] = s2;
	str[++i] = '\0';
	return (str);
}

static int	ft_checker(t_map *map)
{
	int	i;

	i = 0;
	while (map->path[++i])
	{
		if (!ft_strchr("1\n\0", map->path[i]))
			return (0);
	}
	free (map->tmp);
	return (1);
}

void	save_line(t_map *map, int fd)
{
	map->path = NULL;
	while (-42 < map->y_max++)
	{
		map->tmp = get_next_line(fd);
		if (!map->tmp && map->y_max < 2)
			exit(ft_fd_printf(2, "ERROR\nEmpty Line\n") * 0 + 1);
		if (!map->path)
			map->path = map->tmp;
		else
		{
			if (!map->tmp || !map->tmp[0] || ft_checker(map))
				break ;
			map->path = ft_strjoin(map->path, map->tmp);
			free(map->tmp);
		}
		map->path = ft_chrjoin(map->path, 'z');
		if (!map->path)
			exit(ft_fd_printf(2, "ERROR\nChrJoin\n") * 0 + 1);
	}
	map->p = ft_split(map->path, 'z');
	if (!map->p)
		exit(ft_fd_printf(2, "ERROR\nMalloc\n") * 0 + 1);
	parsing(map);
}

void	parsing(t_map *map)
{
	map->y_max--;
	if (map->p[0][0] != '1')
		exit(ft_fd_printf(2, "%s", ERROR_ADD_REMOVE_OBJECTS) * 0 + 1);
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
		if (map->p[map->y][0] == '\n')
			exit(ft_fd_printf(2, "%s", ERROR_EMPTY_MAP) * 0 + 1);
	}
	map->y--;
	if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1
		|| map->g_count < 1)
		exit(ft_fd_printf(2, "%s", ERROR_ADD_REMOVE_OBJECTS) * 0 + 1);
	is_it_one(map, -1, -1);
}

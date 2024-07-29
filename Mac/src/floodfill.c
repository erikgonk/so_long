/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:06:10 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/09 17:38:36 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_map(t_win *win)
{
	int	x;
	int	y;

	y = -1;
	while (win->map.p[++y])
	{
		x = -1;
		while (win->map.p[y][++x] && win->map.p[y][x] != '\n')
			if (win->map.p[y][x] == 'P')
				break ;
		if (win->map.p[y][x] == 'P')
			break ;
	}
	floodfill(win, y, x, " cep");
	last_checker(win, -1, -1);
	floodfill2(win, y, x, "0CEP");
}

void	floodfill(t_win *win, int y, int x, char *pass)
{
	if (x == 0 || y == 0)
		return ;
	else if (x == win->map.x_max || y == win->map.y_max)
		return ;
	else if (!(ft_strchr("0PEC", win->map.p[y][x])))
		return ;
	else if (win->map.p[y][x] == '0')
		win->map.p[y][x] = pass[0];
	else if (win->map.p[y][x] == 'C')
		win->map.p[y][x] = pass[1];
	else if (win->map.p[y][x] == 'E')
		win->map.p[y][x] = pass[2];
	else if (win->map.p[y][x] == 'P')
		win->map.p[y][x] = pass[3];
	floodfill(win, y, x + 1, pass);
	floodfill(win, y + 1, x, pass);
	floodfill(win, y - 1, x, pass);
	floodfill(win, y, x - 1, pass);
	return ;
}

void	floodfill2(t_win *win, int y, int x, char *pass)
{
	if (x == 0 || y == 0)
		return ;
	else if (x == win->map.x_max || y == win->map.y_max)
		return ;
	else if (!(ft_strchr(" pec", win->map.p[y][x])))
		return ;
	else if (win->map.p[y][x] == ' ')
		win->map.p[y][x] = pass[0];
	else if (win->map.p[y][x] == 'c')
		win->map.p[y][x] = pass[1];
	else if (win->map.p[y][x] == 'e')
		win->map.p[y][x] = pass[2];
	else if (win->map.p[y][x] == 'p')
		win->map.p[y][x] = pass[3];
	floodfill2(win, y, x + 1, pass);
	floodfill2(win, y + 1, x, pass);
	floodfill2(win, y - 1, x, pass);
	floodfill2(win, y, x - 1, pass);
	return ;
}

void	last_checker(t_win *win, int x, int y)
{
	while (++y < win->map.y_max)
	{
		x = -1;
		while (++x <= win->map.x_max)
			if (win->map.p[y][x] == 'C' || win->map.p[y][x] == 'E')
				exit(ft_fd_printf(2, "%s", ERROR_MAP_E_NOT_FOUND) * 0 + 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:04:18 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/04 19:04:32 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_win *win, int y, int x, int dir)
{
	if (win->map.c_count == win->map.points && win->map.p[y][x] == 'E')
		exit(ft_fd_printf(1, "YOU WON!\n"));
	if (win->map.p[y][x] == '1' || win->map.p[y][x] == 'E')
	{
		if (dir == RIGHT)
			--win->map.p_x;
		else if (dir == LEFT)
			++win->map.p_x;
		else if (dir == UP)
			++win->map.p_y;
		else if (dir == DOWN)
			--win->map.p_y;
		win->map.event = 0;
	}
	else
		win->map.event = 1;
}

void	print_paco(t_win *win, int y, int x, int dir)
{
	if (dir == RIGHT)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, --x, y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_9);
	}
	else if (dir == LEFT)
	{
			print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
			print_img(win, ++x, y, WALL_BLACK);
			print_img(win, win->map.p_x, win->map.p_y, PACMAN_9);
	}
	else if (dir == UP)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, x, ++y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_9);
	}
	else if (dir == DOWN)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, x, --y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_9);
	}
}
void	print_pac(t_win *win, int y, int x, int dir)
{
	if (dir == RIGHT)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, --x, y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_R);
	}
	else if (dir == LEFT)
	{
			print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
			print_img(win, ++x, y, WALL_BLACK);
			print_img(win, win->map.p_x, win->map.p_y, PACMAN_L);
	}
	else if (dir == UP)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, x, ++y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_U);
	}
	else if (dir == DOWN)
	{
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		print_img(win, x, --y, WALL_BLACK);
		print_img(win, win->map.p_x, win->map.p_y, PACMAN_D);
	}
}

void	movement(t_win *win, int y, int x, int dir)
{
	check_map(win, y, x, dir);
	if (win->map.p[win->map.p_y][win->map.p_x] == 'C')
	{
		win->map.p[win->map.p_y][win->map.p_x] = '0';
		print_img(win, win->map.p_x, win->map.p_y, WALL_BLACK);
		win->map.points++;
	}
	else if (win->map.p[win->map.p_y][win->map.p_x] == 'G')
		print_death(win);
	if (win->map.event == 0)
		return ;
	else
		pacman_move(win, dir);
}
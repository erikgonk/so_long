/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:18:04 by erigonza          #+#    #+#             */
/*   Updated: 2024/07/29 19:56:12 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int value)
{
	exit(value);
}
/*
int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
		exit_window(0);
	else if (keycode == 126 || keycode == 13)
		win->map.move = 1;
	else if (keycode == 125 || keycode == 1)
		win->map.move = 2;
	else if (keycode == 124 || keycode == 2)
		win->map.move = 3;
	else if (keycode == 123 || keycode == 0)
		win->map.move = 4;
	return (0);
}*/

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		exit_window(0);
	else if (keycode == 119 || keycode == 65362)
		win->map.move = 1;
	else if (keycode == 100 || keycode == 65363)
		win->map.move = 3;
	else if (keycode == 115 || keycode == 65364)
		win->map.move = 2;
	else if (keycode == 97 || keycode == 65361)
		win->map.move = 4;
	return (0);
}

int	move_loop(t_win *win)
{
//	int		i;
	int		x;
	int		y;

//	i = 0;
// norm does not approve usleep but works better 
// while (i < 96999999)
//		i++;
	usleep(80000);
	// ghosts_moving(win);
	x = win->map.p_x;
	y = win->map.p_y;
	if (win->map.move == UP && win->map.p[y - 1][x] != '1')
		movement(win, (--win->map.p_y), win->map.p_x, UP);
	else if (win->map.move == RIGHT && win->map.p[y][x + 1] != '1')
		movement(win, win->map.p_y, (++win->map.p_x), RIGHT);
	else if (win->map.move == DOWN && win->map.p[y + 1][x] != '1')
		movement(win, (++win->map.p_y), win->map.p_x, DOWN);
	else if (win->map.move == LEFT && win->map.p[y][x - 1] != '1')
		movement(win, win->map.p_y, (--win->map.p_x), LEFT);
	else
		continuamos(win->map.tmp2, win);
	return (0);
}

void	create_win(t_win *win)
{
	if (win->map.x_max < 10)
		win->win = mlx_new_window(win->mlx, (10 * 34), ((win->map.y_max * 32)
					+ 100), "PAC-MAN");
	else if (win->map.x_max > 1080 || win->map.y_max > 1920)
		exit (ft_fd_printf(2, "%s", ERROR_MAP_TOO_BIG) * 0 + 1);
	else
		win->win = mlx_new_window(win->mlx, (win->map.x_max * 34),
				((win->map.y_max * 32) + 100), "PAC-MAN");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_win	win;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(ft_fd_printf(2, "%s", ERROR_OPEN) * 0 + 1);
	if (argc != 2)
		exit(ft_fd_printf(2, "%s", ERROR_ARGUMENTS) * 0 + 1);
	if (!correct_file(argv[1]))
		exit(ft_fd_printf(2, "%s", ERROR_NAME) * 0 + 1);
	ft_zero(&win.map, fd);
	end_map(&win);
	if (close(fd))
		exit(ft_fd_printf(2, "%s", ERROR_CLOSE) * 0 + 1);
	win.mlx = mlx_init();
	init_images(&win);
	create_win(&win);
	put_base_map(&win);
	mlx_hook(win.win, 2, 1L, key_hook, &win);
	mlx_loop_hook(win.mlx, move_loop, &win);
	mlx_hook(win.win, 17, 1L, exit_window, 0);
	mlx_loop(win.mlx);
	return (0);
}

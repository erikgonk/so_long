/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:18:04 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/04 18:37:04 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int value)
{
	exit(value);
}

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
		exit_window(0);
	else if (keycode == 126 || keycode == 13)
		movement(win, (win->map.p_y - 1), win->map.p_x, UP);
	else if (keycode == 124 || keycode == 2)
		movement(win, win->map.p_y, (win->map.p_x + 1), RIGHT);
	else if (keycode == 125 || keycode == 1)
		movement(win, (win->map.p_y + 1), win->map.p_x, DOWN);
	else if (keycode == 123 || keycode == 0)
		movement(win, win->map.p_y, (win->map.p_x - 1), LEFT);
	return (0);
}

int main(int argc, char **argv)
{
  int			fd;
	t_win		win;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		exit(ft_fd_printf(2, "%s", ERROR_ARGUMENTS) * 0 + 1);
	if (!correct_file(argv[1]))
		exit(ft_fd_printf(2, "%s", ERROR_NAME) * 0 + 1);
	if (fd < 0)
		exit(ft_fd_printf(2, "%s", ERROR_OPEN) * 0 + 1);
	ft_zero(&win.map, fd);
  if (close(fd))
		exit(ft_fd_printf(2, "%s", ERROR_CLOSE) * 0 + 1);
	win.mlx = mlx_init();
	init_images(&win);
	win.win = mlx_new_window(win.mlx, (win.map.x * 34), ((win.map.y * 32) + 75), "so_long");
	put_base_map(&win);
	mlx_hook(win.win, 2, 0, key_hook, &win);
	mlx_hook(win.win, 17, 0, exit_window, 0);
	mlx_loop(win.mlx);
  return (0);
}

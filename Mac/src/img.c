/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:05:09 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/16 14:38:11 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_win *win)
{
	int	i;

	i = -1;
	win->map.sprites = malloc(MAX_SPRITES * sizeof(t_img));
	if (!win->map.sprites)
		exit(ft_fd_printf(2, "%s", ERROR_MALLOC) * 0 + 1);
	while (++i < MAX_SPRITES)
	{
		win->map.sprites[i].img = mlx_xpm_file_to_image(win->mlx, get_path(i),
				&win->map.sprites[i].x, &win->map.sprites[i].y);
		if (!win->map.sprites[i].img)
			exit(ft_fd_printf(2, "ERROR\nImage") * 0 + 1);
	}
	return (0);
}

void	print_img(t_win *win, int y, int x, int n)
{
	if ((n >= 0 && n <= 8) && win->map.moves != -1)
		change_font(win);
	if ((n >= 0 && n <= 8) && win->map.moves == -1)
	{
		win->map.moves++;
	}
	y = y * 32 + 25;
	x = x * 32;
	mlx_put_image_to_window(win->mlx, win->win, win->map.sprites[n].img, y, x);
}

void	extra_print(t_win *win)
{
	print_img(win, ((win->map.x_max / 2) - 3), (win->map.y_max + 1), FONT_0);
	print_img(win, ((win->map.x_max / 2) - 1), (win->map.y_max + 1), FONT_0);
	print_img(win, ((win->map.x_max / 2) + 1), (win->map.y_max + 1), FONT_0);
	print_img(win, ((win->map.x_max / 2) + 3), (win->map.y_max + 1), FONT_0);
	print_img(win, (win->map.x_max / 2) - 2, (win->map.y_max + 2), LOGO);
}

void	print_objects(t_win *win, int y, int x)
{
	print_img(win, x, y, WALL_BLACK);
	if (win->map.p[y][x] == '1')
		print_img(win, x, y, WALL);
	if (win->map.p[y][x] == 'E')
		print_img(win, x, y, EXIT);
	if (win->map.p[y][x] == 'C')
		print_img(win, x, y, DOT);
	if (win->map.p[y][x] == 'G')
		print_img(win, x, y, GHOST_L1);
	if (win->map.p[y][x] == '0')
		print_img(win, x, y, WALL_BLACK);
	if (win->map.p[y][x] == 'P')
	{
		win->map.p_x = x;
		win->map.p_y = y;
		print_img(win, x, y, PACMAN_R);
	}
}

void	put_base_map(t_win *win)
{
	int	y;
	int	x;

	y = -1;
	while (++y < win->map.y_max)
	{
		x = -1;
		while (++x < win->map.x_max)
			print_objects(win, y, x);
	}
	extra_print(win);
}

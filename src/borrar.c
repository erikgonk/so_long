/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:18:45 by erigonza          #+#    #+#             */
/*   Updated: 2024/03/30 16:59:21 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

typedef struct	s_data {
	void	*img;
	int		*img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	int		x;
	int		y;
	int		*img_width;
	int		*img_height;
	void	*mlx;
	void	*win;
	int		bol;
	t_data	img;
}				t_vars;

int	closing(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	keep_moving(t_vars *mlx)
{
	mlx->img_width[0] = 50;
	mlx->img_height[0] = 50;
//	char	*relative_path = "../sprites/Pac-Man/pac_open_right.xpm";
//	mlx->img.img2 = mlx_xpm_file_to_image(mlx->mlx, relative_path, &mlx->img_width[0], &mlx->img_height[0]);
	if (mlx->bol == 1)// right
	{
		if (mlx->x < 1920)
		{
			my_mlx_pixel_put(&mlx->img, mlx->x++, mlx->y, 0x00000000);
			my_mlx_pixel_put(&mlx->img, mlx->x--, mlx->y, 0x00FF0000);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
			mlx->x++;
		}
		else
			mlx->bol = 0;
	}
	else if (mlx->bol == 2)
	{
		if (mlx->x > 0)// left
		{
			my_mlx_pixel_put(&mlx->img, mlx->x--, mlx->y, 0x00000000);
			my_mlx_pixel_put(&mlx->img, mlx->x++, mlx->y, 0x00FF0000);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
			mlx->x--;
		}
		else
			mlx->bol = 0;
	}
	else if (mlx->bol == 3)
	{
		if (mlx->y > 0)// up
		{
			my_mlx_pixel_put(&mlx->img, mlx->x, mlx->y--, 0x00000000);
			my_mlx_pixel_put(&mlx->img, mlx->x, mlx->y++, 0x00FF0000);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
			mlx->y--;
		}
		else
			mlx->bol = 0;
	}
	else if (mlx->bol == 4)
	{
		if (mlx->y < 1080)// down
		{
			my_mlx_pixel_put(&mlx->img, mlx->x, mlx->y++, 0x00000000);
			my_mlx_pixel_put(&mlx->img, mlx->x, mlx->y--, 0x00FF0000);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
			mlx->y++;
		}
		else
			mlx->bol = 0;
	}
	return (0);
}

int	paintover(int keycode, t_vars *mlx)
{
	if (keycode == 124 || keycode == 2)// right
		mlx->bol = 1;
	else if (keycode == 123 || keycode == 13)// left
		mlx->bol = 2;
	if (keycode == 126 || keycode == 0)// up
		mlx->bol = 3;
	else if (keycode == 125 || keycode == 1)// down
		mlx->bol = 4;
	return (0);
}

int main(void)
{
	t_vars	mlx;
//
	mlx.x = 500;
	mlx.y = 500;

// start
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "PAC-MAN");
	mlx.img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
// paint
	mlx_key_hook(mlx.win, paintover, &mlx);
	mlx_loop_hook(mlx.mlx, keep_moving, &mlx);
// close
	mlx_hook(mlx.win, 2, 1L<<0, closing, &mlx.img);
// end
	mlx_loop(mlx.mlx);
	return (0);
}

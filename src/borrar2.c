/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:24:25 by erigonza          #+#    #+#             */
/*   Updated: 2024/03/30 12:45:32 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	position(t_img *img)
{
	int		y;
	int		x;

	y = -1;
	while (++y < img->y)
	{
		x = -1;
		while (img->position[y][++x] != '\n')
			valid_walls(img, x, y);
	}
}

void	valid_walls(t_img *img, int x, int y)
{
	if (img->position[y][x] == '1')// wall
	{
		img->wall[img->w].x = x;
		img->wall[img->w++].y = y;
	}
	else if (img->position[y][x] == '0')// valid
	{
		img->valid[img->v].x = x;
		img->valid[img->v++].y = y;
	}
	else if (img->position[y][x] == 'E')// collectable
	{
		img->end[0].x = x;
		img->end[0].y = y;
	}
	else if (img->position[y][x] == 'C')// exit
	{
		img->collect[img->c].x = x;
		img->collect[img->c].y = y;
	}
	moved(img, x, y);
}

void	moved(t_img *img, int x, int y)
{
	else if (img->position[y][x] == 'M')// enemy
	{
		img->enemy[img->e].x = x;
		img->enemy[img->e].y = y;
	}
	else if (img->position[y][x] == 'P')// pacman
	{
		img->pacman[img->p].x = x;
		img->pacman[img->p].y = y;
	}
}
// E exit
// P pacman
// C coleccionable
// G ghost

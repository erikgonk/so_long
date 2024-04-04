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

void	change_icon(t_win *win)
{
		
}

void	check_map(t_win *win, int x, int y)
{
// WALLS
	if (win->map.p[y - 1][x] == '1')
	{
		win->map.event = 0;
		return ;
	}
	else if (win->map.p[y + 1][x] == '1')
	{
		win->map.event = 0;
		return ;
	}
	else if (win->map.p[y][x - 1] == '1')
	{
		win->map.event = 0;
		return ;
	}
	else if (win->map.p[y - 1][x + 1] == '1')
	{
		win->map.event = 0;
		return ;
	}
	else
		win->map.event = 1;
// Colleccionables
	if (win->map.p[y][x] == 'C')
	{
		change_icon(win);// hacer función para cambiar icono, esta función llama a put_img y elimina coleccionable en este caso
		win->map.points++;
	}
	else if (win->map.p[y][x] == 'G')
		exit(win);

}

void	movement(t_win *win, int y, int x, int dir)
{
	check_map(win, y, x);
	if (win->map.event == 0)
		return ;
	
}
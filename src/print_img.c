/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:27:32 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/05 19:27:35 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  pacman_move(t_win *win, int dir)
{
  printf("%d\n", win->map.moves);
  if (win->map.p_x < win->map.x_max && dir == RIGHT)
  {
    printf("r\n");
    if (win->map.moves % 2 == 0)
      print_pac(win, win->map.p_y, win->map.p_x, PACMAN_9);
    else
      print_pac(win, win->map.p_y, win->map.p_x, RIGHT);
  }
  if (win->map.p_x > 0 && dir == LEFT)
  {
    if (win->map.moves % 2 == 0)
      print_pac(win, win->map.p_y, win->map.p_x, PACMAN_9);
    else
      print_pac(win, win->map.p_y, win->map.p_x, LEFT);
  }
  if (win->map.p_y > 0 && dir == UP)
  {
    if (win->map.moves % 2 == 0)
      print_pac(win, win->map.p_y, win->map.p_x, PACMAN_9);
    else
      print_pac(win, win->map.p_y, win->map.p_x, UP);
  }
  if (win->map.p_y < win->map.y_max && dir == DOWN)
  {
    if (win->map.moves % 2 == 0)
      print_pac(win, win->map.p_y, win->map.p_x, PACMAN_9);
    else
      print_pac(win, win->map.p_y, win->map.p_x, DOWN);
    }
}
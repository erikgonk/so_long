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
  if (win->map.p_x < win->map.x_max && dir == RIGHT)
  {
//    printf("r\n");
    if (win->map.moves % 2 == 0)
      print_paco(win, win->map.p_y, win->map.p_x, RIGHT);
    else
      print_pac(win, win->map.p_y, win->map.p_x, RIGHT);
  }
  if (win->map.p_x > 0 && dir == LEFT)
  {
    if (win->map.moves % 2 == 0)
      print_paco(win, win->map.p_y, win->map.p_x, LEFT);
    else
      print_pac(win, win->map.p_y, win->map.p_x, LEFT);
  }
  if (win->map.p_y > 0 && dir == UP)
  {
    if (win->map.moves % 2 == 0)
      print_paco(win, win->map.p_y, win->map.p_x, UP);
    else
      print_pac(win, win->map.p_y, win->map.p_x, UP);
  }
  if (win->map.p_y < win->map.y_max && dir == DOWN)
  {
    if (win->map.moves % 2 == 0)
      print_paco(win, win->map.p_y, win->map.p_x, DOWN);
    else
      print_pac(win, win->map.p_y, win->map.p_x, DOWN);
  }
}

void  print_death(t_win *win)
{/*
  int i;

  i = 9;
  while (i <= 19)
  {
    print_img(win, win->map.p_x, win->map.p_y, i++);
    usleep(100000);
  }*/
  (void)win;
  printf("YOU LOST!\n");
  exit_window(1);
}

void  change_font(t_win *win)
{
  // int   y = 340;
  // int   x = 500;
 	printf("moves -> %d\n", ++win->map.moves);
  get_abc(win);
  // mlx_put_image_to_window(win->mlx, win->win, win->map.sprites[win->map.a].img, y, x);

  print_img(win, 7, 8, FONT_B);
	print_img(win, 9, 8, FONT_B);
	print_img(win, 11, 8, FONT_B);
	print_img(win, 13, 8, FONT_B);
	print_img(win, 7, 8, win->map.a + 20);
	print_img(win, 9, 8, win->map.b + 20);
	print_img(win, 11, 8, win->map.c + 20);
	print_img(win, 13, 8, win->map.d + 20);
}

void	get_abc(t_win *win)
{
  win->map.a = 0;
  win->map.b = 0;
  win->map.c = 0;
  win->map.d = win->map.moves;
  if (win->map.moves > 999)
  {
    win->map.a = win->map.moves / 1000;
    win->map.b = win->map.moves / 100;
    win->map.c = (win->map.moves / 100) % 10;
    win->map.d = win->map.moves % 10;
  }
  if (win->map.moves > 99)
  {
    win->map.b = win->map.moves / 100;
    win->map.c = (win->map.moves / 10) % 10;
    win->map.d = win->map.moves % 10;
  }
  if (win->map.moves > 9)
  {
    win->map.c = (win->map.moves / 10) % 10;
    win->map.d = win->map.moves % 10;
    return ;
  }
}
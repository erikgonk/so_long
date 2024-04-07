/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:12:13 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/04 18:41:06 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define PACMAN_R 0
# define PACMAN_R0 1
# define PACMAN_L 2
# define PACMAN_L0 3
# define PACMAN_D 4
# define PACMAN_D0 5
# define PACMAN_U 6
# define PACMAN_U0 7
# define PACMAN_9 8
//
# define DPACMAN_1 9
# define DPACMAN_2 10
# define DPACMAN_4 11
# define DPACMAN_6 12
# define DPACMAN_8 13
# define DPACMAN_W 14
# define DPACMAN_10 15
# define DPACMAN_3 16
# define DPACMAN_5 17
# define DPACMAN_7 18
# define DPACMAN_9 19
//
# define FONT_0 20
# define FONT_1 21
# define FONT_2 22
# define FONT_3 23
# define FONT_4 24
# define FONT_5 25
# define FONT_6 26
# define FONT_7 27
# define FONT_8 28
# define FONT_9 29
# define FONT_B 30
//
# define DOT 31
# define EXIT 32
//
# define WALL_BLACK 33 
# define WALL 34
//
# define LOGO 35
//
# define GHOST_1 36 
# define GHOST_2 37
# define GHOST_3 38
# define GHOST_4 39
# define GHOST_5 40
# define GHOST_6 41
# define GHOST_7 42
# define GHOST_8 43
//
//
//
//
// PAC-MAN
# define sprite_1 "sprites/Pac-Man/pac_open_right.xpm"
# define sprite_2 "sprites/Pac-Man/pac_open_right.xpm"
# define sprite_3 "sprites/Pac-Man/pac_open_left.xpm"
# define sprite_4 "sprites/Pac-Man/pac_open_left.xpm"
# define sprite_5 "sprites/Pac-Man/pac_open_down.xpm"
# define sprite_6 "sprites/Pac-Man/pac_open_down.xpm"
# define sprite_7 "sprites/Pac-Man/pac_open_up.xpm"
# define sprite_8 "sprites/Pac-Man/pac_semi_up.xpm"
# define sprite_9 "sprites/Pac-Man/pac_closed.xpm"
// PAC-MAN DEATH
# define sprite_10 "sprites/Pac-Man/Dying/pacman_dying1.xpm"
# define sprite_11 "sprites/Pac-Man/Dying/pacman_dying2.xpm"
# define sprite_12 "sprites/Pac-Man/Dying/pacman_dying4.xpm"
# define sprite_13 "sprites/Pac-Man/Dying/pacman_dying6.xpm"
# define sprite_14 "sprites/Pac-Man/Dying/pacman_dying8.xpm"
# define sprite_15 "sprites/Pac-Man/Dying/pacman_woosh.xpm"
# define sprite_16 "sprites/Pac-Man/Dying/pacman_dying10.xpm"
# define sprite_17 "sprites/Pac-Man/Dying/pacman_dying3.xpm"
# define sprite_18 "sprites/Pac-Man/Dying/pacman_dying5.xpm"
# define sprite_19 "sprites/Pac-Man/Dying/pacman_dying7.xpm"
# define sprite_20 "sprites/Pac-Man/Dying/pacman_dying9.xpm"
// FONT
# define sprite_21 "sprites/Other/Fonts/0.xpm"
# define sprite_22 "sprites/Other/Fonts/1.xpm"
# define sprite_23 "sprites/Other/Fonts/2.xpm"
# define sprite_24 "sprites/Other/Fonts/3.xpm"
# define sprite_25 "sprites/Other/Fonts/4.xpm"
# define sprite_26 "sprites/Other/Fonts/5.xpm"
# define sprite_27 "sprites/Other/Fonts/6.xpm"
# define sprite_28 "sprites/Other/Fonts/7.xpm"
# define sprite_29 "sprites/Other/Fonts/8.xpm"
# define sprite_30 "sprites/Other/Fonts/9.xpm"
# define sprite_31 "sprites/Other/Fonts/black.xpm"
// DOTS small - big
# define sprite_32 "sprites/Other/Pacdots/pacdot_powerup.xpm"
# define sprite_33 "sprites/Other/Portal/portal.xpm"
// WALL
# define sprite_34 "sprites/Other/Walls/black.xpm"
# define sprite_35 "sprites/Other/Walls/wall.xpm"
// LOGO
# define sprite_36 "sprites/Other/Logo/logo.xpm"
// GHOST
# define sprite_37 "sprites/Ghosts/O/ghost_down1.xpm"
# define sprite_38 "sprites/Ghosts/O/ghost_down2.xpm"
# define sprite_39 "sprites/Ghosts/O/ghost_left1.xpm"
# define sprite_40 "sprites/Ghosts/O/ghost_left2.xpm"
# define sprite_41 "sprites/Ghosts/O/ghost_right1.xpm"
# define sprite_42 "sprites/Ghosts/O/ghost_right2.xpm"
# define sprite_43 "sprites/Ghosts/O/ghost_up1.xpm"
# define sprite_44 "sprites/Ghosts/O/ghost_up2.xpm"
//
//
//
// RANDOM
# define MAX_SPRITES 44
# define UP 1
# define DOWN 2
# define RIGHT 3
# define LEFT 4
//
//
//
// ERRORS
# define ERROR_ARGUMENTS "Error\nJust One Argument Is Admited"
# define ERROR_NAME "Error\nCorrect Name"
# define ERROR_OPEN "Error\nOpen Failed"
# define ERROR_CLOSE "Error\nClose Failed"
# define ERROR_SIZE "Error\nMap soo long ;)"
# define ERROR_MAP_OBJECTS "Error\nThere Are Objects Left"
# define ERROR_EMPTY_MAP "Error\nNew Line Empty"
# define ERROR_MALLOC "Error\nMalloc Failed"
# define ERROR_ADD_REMOVE_OBJECTS "Error\nAdd Or Remove Objects"

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}	t_img;

typedef struct s_map {
	char	**p;
	int		validated;
	int		x;
	int		x_max;
	int		y;
	int		y_max;
	int		bol;
	int		event;
	int		p_count;
	int		e_count;
	int		c_count;
	int		g_count;
	int		p_x;
	int		p_y;
	int		points;
	int		moves;
	int		paroimpar;
	int		a;
	int		b;
	int		c;
	int		d;
	t_img	*sprites;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_win;

int		exit_window(int value);
int		key_hook(int keycode, t_win *win);

int		init_images(t_win *win);
void	print_img(t_win *win, int y, int x, int n);
void	print_objects(t_win *win, int y, int x);
void	put_base_map(t_win *win);

int		correct_file(char *name);
void	save_line(t_map *map, int fd);
void	parsing(t_map *map);

void	check_map(t_win *win, int x, int y, int dir);
void	print_paco(t_win *win, int y, int x, int dir);
void	print_pac(t_win *win, int y, int x, int dir);
void	movement(t_win *win, int y, int x, int dir);

void  ft_zero(t_map *map, int fd);
void  check_x(t_map *map);
void	init_global1(char **sprites);
void	init_global2(char **sprites);
char	*get_path(int n);

void  pacman_move(t_win *win, int dir);
void  print_death(t_win *win);
void  change_font(t_win *win);
void	get_abc(t_win *win);

char	*get_next_line(int fd);
//
void	*ft_calloc(int count, int size);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		checker(char *buffer);
char	*ft_free(char *buffer, char *line);

#endif


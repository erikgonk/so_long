/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:26 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/04 18:41:15 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  ft_zero(t_map *map, int fd)
{
  map->validated = 0;
  map->x = 0;
  map->x_max = 0;
  map->y = 0;
  map->y_max = -1;
  map->bol = 1;
  map->event = 0;
  map->p_count = 0;
  map->e_count = 0;
  map->c_count = 0;
  map->g_count = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->points = 0;
	map->paroimpar = 0;
	map->moves = -1;
  save_line(map, fd);
}

void  check_x(t_map *map)
{
  if (map->bol == 1)
  {
    map->x_max = map->x;
    map->bol = 0;
  }
}

void	init_global1(char **sprites)
{
	sprites[0] = sprite_1;
	sprites[1] = sprite_2;
	sprites[2] = sprite_3;
	sprites[3] = sprite_4;
	sprites[4] = sprite_5;
	sprites[5] = sprite_6;
	sprites[6] = sprite_7;
	sprites[7] = sprite_8;
	sprites[8] = sprite_9;
	sprites[9] = sprite_10;
	sprites[10] = sprite_11;
	sprites[11] = sprite_12;
	sprites[12] = sprite_13;
	sprites[13] = sprite_14;
	sprites[14] = sprite_15;
	sprites[15] = sprite_16;
	sprites[16] = sprite_17;
	sprites[17] = sprite_18;
	sprites[18] = sprite_19;
	sprites[19] = sprite_20;
	sprites[20] = sprite_21;
	sprites[21] = sprite_22;
	sprites[22] = sprite_23;
	sprites[23] = sprite_24;
	sprites[24] = sprite_25;
}

void	init_global2(char **sprites)
{
	sprites[25] = sprite_26;
	sprites[26] = sprite_27;
	sprites[27] = sprite_28;
	sprites[28] = sprite_29;
	sprites[29] = sprite_30;
	sprites[30] = sprite_31;
	sprites[31] = sprite_32;
	sprites[32] = sprite_33;
	sprites[33] = sprite_34;
	sprites[34] = sprite_35;
	sprites[35] = sprite_36;
	sprites[36] = sprite_37;
	sprites[37] = sprite_38;
	sprites[38] = sprite_39;
	sprites[39] = sprite_40;
	sprites[40] = sprite_41;
	sprites[41] = sprite_42;
	sprites[42] = sprite_42;
	sprites[43] = sprite_42;
}

char	*get_path(int n)
{
	static char	*sprites[MAX_SPRITES];

	if (!*sprites)
	{
		init_global1(sprites);
		init_global2(sprites);
	}
	if (n < MAX_SPRITES && n >= 0)
		return (sprites[n]);
	else
		return (NULL);
}

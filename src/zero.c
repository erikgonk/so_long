/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:26 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/09 17:35:59 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_zero(t_map *map, int fd)
{
	map->validated = 0;
	map->x = 0;
	map->x_max = 0;
	map->y = 0;
	map->y_max = 0;
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
	map->e_found = 0;
	map->move = 0;
	map->line_count = 0;
	map->tmp2 = 0;
	save_line(map, fd);
}

void	init_global1(char **sprites)
{
	sprites[0] = SPRITE_1;
	sprites[1] = SPRITE_2;
	sprites[2] = SPRITE_3;
	sprites[3] = SPRITE_4;
	sprites[4] = SPRITE_5;
	sprites[5] = SPRITE_6;
	sprites[6] = SPRITE_7;
	sprites[7] = SPRITE_8;
	sprites[8] = SPRITE_9;
	sprites[9] = SPRITE_10;
	sprites[10] = SPRITE_11;
	sprites[11] = SPRITE_12;
	sprites[12] = SPRITE_13;
	sprites[13] = SPRITE_14;
	sprites[14] = SPRITE_15;
	sprites[15] = SPRITE_16;
	sprites[16] = SPRITE_17;
	sprites[17] = SPRITE_18;
	sprites[18] = SPRITE_19;
	sprites[19] = SPRITE_20;
	sprites[20] = SPRITE_21;
	sprites[21] = SPRITE_22;
	sprites[22] = SPRITE_23;
	sprites[23] = SPRITE_24;
	sprites[24] = SPRITE_25;
}

void	init_global2(char **sprites)
{
	sprites[25] = SPRITE_26;
	sprites[26] = SPRITE_27;
	sprites[27] = SPRITE_28;
	sprites[28] = SPRITE_29;
	sprites[29] = SPRITE_30;
	sprites[30] = SPRITE_31;
	sprites[31] = SPRITE_32;
	sprites[32] = SPRITE_33;
	sprites[33] = SPRITE_34;
	sprites[34] = SPRITE_35;
	sprites[35] = SPRITE_36;
	sprites[36] = SPRITE_37;
	sprites[37] = SPRITE_38;
	sprites[38] = SPRITE_39;
	sprites[39] = SPRITE_40;
	sprites[40] = SPRITE_41;
	sprites[41] = SPRITE_42;
	sprites[42] = SPRITE_42;
	sprites[43] = SPRITE_42;
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

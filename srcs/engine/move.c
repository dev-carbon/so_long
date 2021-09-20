/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:57:10 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 15:57:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_coor	normalize_position(t_coor pos, t_map map)
{
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x > map.size.width)
		pos.x = map.size.width;
	if (pos.y < 0)
		pos.y = 0;
	else if (pos.y > map.size.height)
		pos.y = map.size.height;
	return (pos);
}

void    move(int key, t_coor pos, t_data *data)
{
    pos = normalize_position(pos, *data->map);
	if (data->map->matrix[pos.y][pos.x] != MAP_WALL	&& is_valid_key(key))
	{
		data->player->pos = pos;
		printf("movement count: %d\n", ++data->player->move);
	}
}

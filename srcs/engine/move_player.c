/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:19:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 19:19:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_player(t_data *data)
{
	t_coor	pos;

	pos = data->player->pos;
	pos.x += data->player->walk_dir.x;
	pos.y += data->player->walk_dir.y;
	if (pos.x < 0)
		pos.x = 0;
	if (pos.x > data->map->size.width)
		pos.x = data->map->size.width;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > data->map->size.height)
		pos.y = data->map->size.height;
	if (data->map->matrix[pos.y][pos.x] != MAP_WALL)
		data->player->pos = pos;
}

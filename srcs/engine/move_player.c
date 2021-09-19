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

t_data	*move_player(t_data *data)
{
	t_coor	pos;

	pos = data->player->pos;
	pos.x += data->player->walk_dir.x;
	pos.y += data->player->walk_dir.y;
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x > data->map->size.width)
		pos.x = data->map->size.width;
	if (pos.y < 0)
		pos.y = 0;
	else if (pos.y > data->map->size.height)
		pos.y = data->map->size.height;
	if (data->map->matrix[pos.y][pos.x] == MAP_COLLECTIBLE)
	{
		data->player->collected++;
		data->map->matrix[pos.y][pos.x] = MAP_SPACE;
	}
	else if (data->map->matrix[pos.y][pos.x] == MAP_EXIT)
	{
		data->map->matrix[pos.y][pos.x] = MAP_SPACE;
		close_game("player exited map\n", EXIT_SUCCESS, data);
	}
	if (data->map->matrix[pos.y][pos.x] != MAP_WALL)
	{
		data->player->pos = pos;
		printf("movement count: %d\n", ++data->player->move);
	}
	return (data);
}

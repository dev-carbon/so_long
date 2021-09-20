/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:03:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 16:03:46 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drivers.h"

t_data	*so_long(int key, t_data *data)
{
	t_coor	pos;

	pos = data->player->pos;
	pos.x += data->player->walk_dir.x;
	pos.y += data->player->walk_dir.y;
	move(key, pos, data);
	collect(pos, data);
	if (data->map->matrix[pos.y][pos.x] == MAP_EXIT
		&& data->config->num_collectibles == 0)
		escape(pos, data);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:57:16 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 15:57:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_data	*set_items(t_coor pos, t_data *data)
{
	t_collectibles	*buff;

	buff = data->config->collectibles;
	while (buff != NULL)
	{
		if (buff->pos.x == pos.x && buff->pos.y == pos.y)
		{
			buff->is_items = 1;
			break ;
		}
		buff = buff->next;
	}
	return (data);
}

t_data	*collect(t_coor pos, t_data *data)
{
	if (data->map->matrix[pos.y][pos.x] == MAP_COLLECTIBLE)
	{
		data->player->items++;
		data->config->num_collectibles--;
		data->map->matrix[pos.y][pos.x] = MAP_SPACE;
		set_items(pos, data);
	}
	return (data);
}

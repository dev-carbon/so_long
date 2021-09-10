/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:54:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 12:54:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_player(t_coor pos, t_map map, t_size tile_size)
{
	int	x;
	int	y;

	x = (int)floor(pos.x / tile_size.width);
	y = (int)floor(pos.y / tile_size.height);
	if (x >= 0 && x < map.size.width && y >= 0 && y < map.size.height)
		if (*(*(map.matrix + y) + x) == MAP_PLAYER)
			return (1);
	return (0);
}

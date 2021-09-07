/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:17:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/06 16:17:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_map(t_window win, t_map map, t_data data)
{
	t_coor	pt;
	t_coor	start;

	pt.y = -1;
	while (++pt.y < map.size.height)
	{
		pt.x = -1;
		while (++pt.x < map.size.width)
		{
			start.x = pt.x * data.tile_size.width + data.offset.x;
			start.y = pt.y * data.tile_size.height + data.offset.y;
			if (*(*(data.map->matrix + pt.y) + pt.x) == MAP_WALL)
				render_rectangle(*data.window, start, data.tile_size, 0x666666);
			else if (*(*(data.map->matrix + pt.y) + pt.x) == MAP_COLLECTIBLE)
				render_rectangle(*data.window, start, data.tile_size, 0x664266);
			else if (*(*(data.map->matrix + pt.y) + pt.x) == MAP_EXIT)
				render_rectangle(*data.window, start, data.tile_size, 0x338833);
			else
				render_rectangle(*data.window, start, data.tile_size, 0xFFFFFF);
		}
	}
}

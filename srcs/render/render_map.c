/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 01:51:14 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/22 01:51:16 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_map(t_window win, t_map map, t_data data)
{
	int			color;
	t_coor		pos;
	t_coor		texel;
	t_asset		asset;

	pos.y = -1;
	while (++pos.y < map.size.height * data.config->tile_size.height)
	{
		pos.x = -1;
		while (++pos.x < map.size.width * data.config->tile_size.width)
		{
			asset = get_asset(pos, map, data);
			texel = get_texel(pos, asset.size, data.config->tile_size);
			color = asset.img.data[(asset.size.width * texel.y) + texel.x];
			win.img.data[(win.size.width * pos.y) + pos.x]
				= color;
		}
	}
}

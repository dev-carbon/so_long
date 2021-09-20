/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:59:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/08 13:59:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_map(t_window win, t_map map, t_data data)
{
	t_coor		pos;
	t_coor		texel;
	t_asset	asset;

	pos.y = -1;
	while (++pos.y < map.size.height * data.config->tile_size.height)
	{
		pos.x = -1;
		while (++pos.x < map.size.width * data.config->tile_size.width)
		{
			asset = get_asset(pos, map, data);
			texel = get_texel(pos, asset.size, data.config->tile_size);
			win.img.data[(win.size.width * pos.y) + pos.x]
				= asset.img.data[(asset.size.width * texel.y) + texel.x];
		}
	}
}

static void	render_player(t_window win, t_player player, t_data data)
{
	t_coor		pos;
	t_coor		texel;
	t_coor		start;
	t_asset	asset;

	pos.y = player.pos.y * data.config->tile_size.height;
	pos.x = player.pos.x * data.config->tile_size.width;
	start = pos;
	asset = data.assets[ASSET_PLAYER];
	while (pos.y < start.y + data.config->tile_size.height)
	{
		pos.x = start.x;
		while (pos.x < start.x + data.config->tile_size.width)
		{
			texel = get_texel(pos, asset.size, data.config->tile_size);
			win.img.data[(win.size.width * pos.y) + pos.x]
				= asset.img.data[(asset.size.width * texel.y) + texel.x];
			pos.x++;
		}
		pos.y++;
	}
}

void	render_world2d(t_window win, t_map map, t_data data)
{
	render_map(win, map, data);
	render_player(win, *data.player, data);
}

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
#include "utils.h"
#include <stdlib.h>

static void	render_map(t_window win, t_map map, t_data data)
{
	t_coor		pos;
	t_coor		texel;
	t_texture	texture;

	pos.y = -1;
	while (++pos.y < map.size.height * data.tile_size.height)
	{
		pos.x = -1;
		while (++pos.x < map.size.width * data.tile_size.width)
		{
			texture = get_texture(pos, map, data);
			texel = get_texel(pos, texture.size, data.tile_size);
		
			win.img.data[(win.size.width * pos.y) + pos.x] = texture.img.data[(texture.size.width * texel.y) + texel.x];
		}
	}
}

static void	render_player(t_window win, t_player player, t_data data)
{
	t_coor		pos;
	t_coor		texel;
	t_coor		start;
	t_texture	texture;

	pos.y = player.pos.y * data.tile_size.height;
	pos.x = player.pos.x * data.tile_size.width;
	start = pos;
	texture = data.textures[TEXTURE_DOLPHIN];
	while (pos.y < start.y + data.tile_size.height)
	{
		pos.x = start.x;
		while (pos.x < start.x + data.tile_size.width)
		{
			texel = get_texel(pos, texture.size, data.tile_size);
			win.img.data[(win.size.width * pos.y) + pos.x] = texture.img.data[(texture.size.width * texel.y) + texel.x];
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
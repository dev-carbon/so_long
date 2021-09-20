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
	int			color;
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
			color = asset.img.data[(asset.size.width * texel.y) + texel.x];
			win.img.data[(win.size.width * pos.y) + pos.x]
				= color;
		}
	}
}

static void render_exit(t_window win, t_coor epos, t_data data)
{
	int			color;
	t_coor		pos;
	t_coor		texel;
	t_coor		start;
	t_asset		asset;

	pos.x = epos.x * data.config->tile_size.width;
	pos.y = epos.y * data.config->tile_size.height;
	start = pos;
	asset = data.assets[ASSET_EXIT];
	while (pos.y < start.y + data.config->tile_size.height)
	{
		pos.x = start.x;
		while (pos.x < start.x + data.config->tile_size.width)
		{
			texel = get_texel(pos, asset.size, data.config->tile_size);
			color = asset.img.data[(asset.size.width * texel.y) + texel.x];
			if (color != 0x3D253B && color != 0x362030
				&& color != 0x927A5D)
				win.img.data[(win.size.width * pos.y) + pos.x]
					= color;
			pos.x++;
		}
		pos.y++;
	}
}

static void	render_collectibles(t_window win, t_collectibles *c, t_data data)
{
	t_coor			texel;
	t_coor			pos;
	t_coor			start;
	t_collectibles	*buff;
	t_asset			asset;
	int				color;

	buff = c;
	asset = data.assets[ASSET_COLLECTIBLE];
	while (buff != NULL)
	{
		pos.x = buff->pos.x * data.config->tile_size.width;
		pos.y = buff->pos.y * data.config->tile_size.height;
		start = pos;
		while (pos.y < start.y + data.config->tile_size.height)
		{
			if (!buff->is_items)
			{
				pos.x = start.x;
				while (pos.x < start.x + data.config->tile_size.width)
				{
					texel = get_texel(pos, asset.size, data.config->tile_size);
					color = asset.img.data[(asset.size.width * texel.y) + texel.x];
					if (color != 0xC5D2FF)
						win.img.data[(win.size.width * pos.y) + pos.x]
							= color;
					pos.x++;
				}
			}
			pos.y++;
		}
		buff = buff->next;
	}
}

static void	render_player(t_window win, t_player player, t_data data)
{
	int			color;
	t_coor		pos;
	t_coor		texel;
	t_coor		start;
	t_asset	asset;

	pos.x = player.pos.x * data.config->tile_size.width;
	pos.y = player.pos.y * data.config->tile_size.height;
	start = pos;
	asset = data.assets[ASSET_PLAYER];
	while (pos.y < start.y + data.config->tile_size.height)
	{
		pos.x = start.x;
		while (pos.x < start.x + data.config->tile_size.width)
		{
			texel = get_texel(pos, asset.size, data.config->tile_size);
			color = asset.img.data[(asset.size.width * texel.y) + texel.x];
			if (color != 0x9EB3EF)
				win.img.data[(win.size.width * pos.y) + pos.x]
					= color;
			pos.x++;
		}
		pos.y++;
	}
}

void	render_world2d(t_window win, t_map map, t_data data)
{
	render_map(win, map, data);
	render_collectibles(win, data.config->collectibles, data);
	render_exit(win, data.config->exit_pos, data);
	render_player(win, *data.player, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 01:34:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/22 01:34:46 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_collectible(t_window win, t_collectible *c, t_asset asset,
	t_data data)
{
	t_coor			pos;
	t_coor			start;
	t_coor			texel;
	int				color;

	pos.x = c->pos.x * data.config->tile_size.width;
	pos.y = c->pos.y * data.config->tile_size.height;
	start = pos;
	while (pos.y < start.y + data.config->tile_size.height)
	{
		pos.x = start.x;
		while (pos.x < start.x + data.config->tile_size.width)
		{
			texel = get_texel(pos, asset.size, data.config->tile_size);
			color = asset.img.data[(asset.size.width * texel.y) + texel.x];
			if (color != 0xC5D2FF)
				win.img.data[(win.size.width * pos.y) + pos.x] = color;
			pos.x++;
		}
		pos.y++;
	}
}

void	render_collectibles(t_window win, t_collectible *c, t_data data)
{
	t_collectible	*buff;
	t_asset			asset;

	buff = c;
	asset = data.assets[ASSET_COLLECTIBLE];
	while (buff != NULL)
	{
		if (!buff->is_collected)
			render_collectible(win, buff, asset, data);
		buff = buff->next;
	}
}

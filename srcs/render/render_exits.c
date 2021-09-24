/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 01:46:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/22 01:46:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_exit(t_window win, t_exit *c, t_asset asset,
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
			if (color != 0x3D253B && color != 0x362030)
				win.img.data[(win.size.width * pos.y) + pos.x]
					= color;
			pos.x++;
		}
		pos.y++;
	}
}

void	render_exits(t_window win, t_exit *exits, t_data data)
{
	t_exit	*buff;
	t_asset	asset;

	buff = exits;
	asset = data.assets[ASSET_EXIT];
	while (buff != NULL)
	{
		render_exit(win, buff, asset, data);
		buff = buff->next;
	}
}

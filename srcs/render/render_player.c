/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 01:32:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/22 01:32:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_player(t_window win, t_player player, t_data data)
{
	int		color;
	t_coor	pos;
	t_coor	texel;
	t_coor	start;
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

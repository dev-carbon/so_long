/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:30:44 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_asset	*load_asset(t_window win, t_asset *asset)
{
	asset->img.ptr = mlx_xpm_file_to_image(win.mlx_ptr, asset->path,
			&asset->size.width, &asset->size.height);
	if (!asset->img.ptr)
		return (NULL);
	asset->img.data = (int *)mlx_get_data_addr(asset->img.ptr,
			&asset->img.bpp, &asset->img.line_length, &asset->img.endian);
	if (!asset->img.data)
		return (NULL);
	return (asset);
}

t_data	*set_assets(t_data *data)
{
	data->assets[ASSET_WALL].path = "./assets/wall.xpm";
	data->assets[ASSET_SPACE].path = "./assets/space.xpm";
	data->assets[ASSET_COLLECTIBLE].path = "./assets/collectible.xpm";
	data->assets[ASSET_PLAYER].path = "./assets/player.xpm";
	data->assets[ASSET_EXIT].path = "./assets/exit.xpm";
	if (!(load_asset(*data->window, &data->assets[ASSET_WALL])))
		quit("Unable to load asset wall.\n", EXIT_FAILURE, data);
	if (!(load_asset(*data->window, &data->assets[ASSET_SPACE])))
		quit("Unable to load asset space.\n", EXIT_FAILURE, data);
	if (!(load_asset(*data->window, &data->assets[ASSET_COLLECTIBLE])))
		quit("Unable to load asset collectible.\n", EXIT_FAILURE, data);
	if (!(load_asset(*data->window, &data->assets[ASSET_PLAYER])))
		quit("Unable to load asset player.\n", EXIT_FAILURE, data);
	if (!(load_asset(*data->window, &data->assets[ASSET_EXIT])))
		quit("Unable to load asset exit.\n", EXIT_FAILURE, data);
	return (data);
}

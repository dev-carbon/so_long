/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:47:39 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 18:47:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_asset	get_asset(t_coor pos, t_map map, t_data data)
{
	if (is_wall(pos, map, data.config->tile_size))
		return (data.assets[ASSET_WALL]);
	if (is_collectible(pos, map, data.config->tile_size))
		return (data.assets[ASSET_COLLECTIBLE]);
	if (is_exit(pos, map, data.config->tile_size))
		return (data.assets[ASSET_EXIT]);
	return (data.assets[ASSET_SPACE]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:47:39 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 18:47:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_texture	get_texture(t_coor pos, t_map map, t_data data)
{
	if (is_wall(pos, map, data.config->tile_size))
		return (data.textures[TEXTURE_WALL]);
	if (is_collectible(pos, map, data.config->tile_size))
		return (data.textures[TEXTURE_FISH]);
	if (is_exit(pos, map, data.config->tile_size))
		return (data.textures[TEXTURE_EXIT]);
	return (data.textures[TEXTURE_WATER]);
}

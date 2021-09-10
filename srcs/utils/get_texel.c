/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:48:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 18:48:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_coor	get_texel(t_coor pos, t_size texture_size, t_size tile_size)
{
	t_coor texel;

	texel.x = (pos.x * texture_size.width / tile_size.width) % texture_size.width;
	texel.y = (pos.y * texture_size.height / tile_size.height) % texture_size.height;
	return (texel);
}

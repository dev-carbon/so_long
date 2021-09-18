/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:30:44 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_texture	*load_texture(t_window win, t_texture *texture)
{
	if (!(texture->img.ptr = mlx_xpm_file_to_image(win.mlx_ptr, texture->path,
		&texture->size.width, &texture->size.height)))
		return (NULL);
	if (!(texture->img.data = (int*)mlx_get_data_addr(texture->img.ptr,
		&texture->img.bpp, &texture->img.line_length, &texture->img.endian)))
		return (NULL);
	return (texture);
}

t_data	*set_textures(t_data *data)
{
	data->textures[TEXTURE_WALL].path = "./textures/wall.xpm";
	data->textures[TEXTURE_WATER].path = "./textures/water.xpm";
	data->textures[TEXTURE_FISH].path = "./textures/fish.xpm";
	data->textures[TEXTURE_DOLPHIN].path = "./textures/dolphin.xpm";
	data->textures[TEXTURE_EXIT].path = "./textures/exit.xpm";
	if (!(load_texture(*data->window, &data->textures[TEXTURE_WALL])))
		close_game("Unable to load texture wall.\n", EXIT_FAILURE, data);
	if (!(load_texture(*data->window, &data->textures[TEXTURE_WATER])))
		close_game("Unable to load texture water.\n", EXIT_FAILURE, data);
	if (!(load_texture(*data->window, &data->textures[TEXTURE_FISH])))
		close_game("Unable to load texture fish.\n", EXIT_FAILURE, data);
	if (!(load_texture(*data->window, &data->textures[TEXTURE_DOLPHIN])))
		close_game("Unable to load texture dolphin.\n", EXIT_FAILURE, data);
	if (!(load_texture(*data->window, &data->textures[TEXTURE_EXIT])))
		close_game("Unable to load texture exit.\n", EXIT_FAILURE, data);
	return (data);
}

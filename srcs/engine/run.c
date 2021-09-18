/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:51:15 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 02:51:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	run(t_data *data)
{
	data->window->img.ptr = mlx_new_image(data->window->mlx_ptr,
		data->window->size.width, data->window->size.height);
	data->window->img.data =(int *)mlx_get_data_addr(data->window->img.ptr,
		&data->window->img.bpp, &data->window->img.line_length,
			&data->window->img.endian);
	render_world2d(*data->window, *data->map, *data);
	mlx_put_image_to_window(data->window->mlx_ptr,
		data->window->mlx_win, data->window->img.ptr,
			data->config->offset.x, data->config->offset.y);
	return (0);
}

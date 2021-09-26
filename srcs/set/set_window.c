/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:29:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:29:04 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*set_window(t_data *data)
{
	if (data->window == NULL)
		init_window(data);
	data->window->mlx_ptr = mlx_init();
	if (!data->window->mlx_ptr)
		quit("mlx_init() mlx_ptr\n", EXIT_FAILURE, data);
	data->window->size.width = data->map->size.width
		* data->config->tile_size.width;
	data->window->size.height = data->map->size.height
		* data->config->tile_size.height;
	data->window->mlx_win = mlx_new_window(data->window->mlx_ptr,
			data->window->size.width, data->window->size.height, APP_NAME);
	if (!data->window->mlx_win)
		quit("mlx_new_window() mlx_win\n", EXIT_FAILURE, data);
	return (data);
}

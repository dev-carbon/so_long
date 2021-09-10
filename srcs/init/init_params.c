/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:36:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_params(t_data *data)
{
	int min;
	int max;

	min = ft_min(data->window->size.width, data->window->size.height);
	max = ft_max(data->map->size.width, data->map->size.height);
	data->config->tile_size.width = min / max;
	data->config->tile_size.height = min / max;
	data->config->offset.x = (data->window->size.width - data->map->size.width *
		data->config->tile_size.width) / 2;
	data->config->offset.y = (data->window->size.height - data->map->size.height *
		data->config->tile_size.height) / 2;
	return (data);
}

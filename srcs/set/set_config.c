/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:00:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:00:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_data	*set_config(t_data *data)
{
	int	min;
	int	max;

	min = ft_min(data->window->size.width, data->window->size.height);
	max = ft_max(data->map->size.width, data->map->size.height);
	data->config->tile_size.width = min / max;
	data->config->tile_size.height = min / max;
	data->config->offset.x = (data->window->size.width)
		- (data->map->size.width * data->config->tile_size.width) / 2;
	data->config->offset.y = (data->window->size.height)
		- (data->map->size.height * data->config->tile_size.height) / 2;
	return (data);
}

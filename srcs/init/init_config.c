/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:57:37 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 14:57:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_config(t_data *data)
{
	data->config = (t_config *)malloc(sizeof(t_config));
	if (data->config == NULL)
		quit("Unable to init config\n", EXIT_FAILURE, data);
	data->config->num_collectibles = 0;
	data->config->num_exits = 0;
	data->config->num_players = 0;
	data->config->tile_size.width = TILE_SIZE;
	data->config->tile_size.height = TILE_SIZE;
	data->config->start_pos.x = -1;
	data->config->start_pos.y = -1;
	data->config->collectibles = NULL;
	data->config->exits = NULL;
	return (data);
}

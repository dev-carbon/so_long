/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:40:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_data	*init_config(t_data *data)
{
	data->config->num_collectibles = 0;
	data->config->tile_size.width = TILE_SIZE;
	data->config->tile_size.height = TILE_SIZE;
	data->config->start_pos.x = -1;
	data->config->start_pos.y = -1;
	data->config->exit_pos.x = -1;
	data->config->exit_pos.y = -1;
	return (data);
}

static t_data	*init_player(t_data *data)
{
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->player->move = 0;
	data->player->collected = 0;
	return (data);
}

t_data	*init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, NULL);
	data->window = (t_window *)malloc(sizeof(t_window));
	if (data->window == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->config = (t_config *)malloc(sizeof(t_config));
	if (data->config == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	init_config(data);
	init_player(data);
	data->rows = NULL;
	return (data);
}

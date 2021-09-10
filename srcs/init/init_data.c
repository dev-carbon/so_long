/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:40:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"

t_data	*init_data(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->window = (t_window *)malloc(sizeof(t_window));
	data->map = (t_map *)malloc(sizeof(t_map));
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data || !data->window || data->map || data->player)
		close_game("Unable to allocate sufficient memory\n", 1, NULL);
	data->map->size.width = 0;
	data->map->size.height = 0;
	data->player->pos.x = -1;
	data->player->pos.y = -1;
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->offset.x = 0;
	data->offset.y = 0;
	data->num_collectibles = 0;
	data->exit_pos.x = -1;
	data->exit_pos.y = -1;
	data->start_pos.x = -1;
	data->start_pos.y = -1;
	data->rows = NULL;
	return (data);
}

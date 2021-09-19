/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:35:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:35:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*set_player(t_data *data)
{
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->player->pos = data->config->start_pos;
	data->player->move = 0;
	data->player->collected = 0;
	return (data);
}

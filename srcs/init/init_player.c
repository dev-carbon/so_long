/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:57:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 14:57:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_player(t_data *data)
{
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == NULL)
		quit("Unable to init player\n", EXIT_FAILURE, data);
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->player->moves = 0;
	data->player->items = 0;
	return (data);
}

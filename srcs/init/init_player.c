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
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->player->move = 0;
	data->player->collected = 0;
	return (data);
}

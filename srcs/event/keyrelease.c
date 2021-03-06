/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:57:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:24:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	keyrelease(int key, t_data *data)
{
	if (key == KEY_Z)
		data->player->walk_dir.y = 0;
	else if (key == KEY_S)
		data->player->walk_dir.y = 0;
	else if (key == KEY_D)
		data->player->walk_dir.x = 0;
	else if (key == KEY_Q)
		data->player->walk_dir.x = 0;
	return (0);
}

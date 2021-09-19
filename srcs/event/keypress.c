/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:56:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:23:14 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	keypress(int key, t_data *data)
{
	if (key == KEY_Z)
		data->player->walk_dir.y = -1;
	else if (key == KEY_S)
		data->player->walk_dir.y = +1;
	else if (key == KEY_D)
		data->player->walk_dir.x = +1;
	else if (key == KEY_Q)
		data->player->walk_dir.x = -1;
	else if (key == KEY_ESC)
		close_game("bye!\n", EXIT_SUCCESS, data);
	move_player(data);
	refresh(data);
	return (0);
}

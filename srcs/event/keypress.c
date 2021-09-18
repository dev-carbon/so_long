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
	if (key == KEY_S)
		data->player->walk_dir.y = +1;
	if (key == KEY_D)
		data->player->walk_dir.x = +1;
	if (key == KEY_Q)
		data->player->walk_dir.x = -1;
	if (key == KEY_ESC)
		close_game("bye!\n", EXIT_SUCCESS, data);
	move_player(data);
	data->window->img.ptr = mlx_new_image(data->window->mlx_ptr,
		data->window->size.width, data->window->size.height);
	data->window->img.data =(int *)mlx_get_data_addr(data->window->img.ptr,
		&data->window->img.bpp, &data->window->img.line_length,
			&data->window->img.endian);
	render_world2d(*data->window, *data->map, *data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->mlx_win,
		data->window->img.ptr, data->config->offset.x,
			data->config->offset.y);
	mlx_destroy_image(data->window->mlx_ptr, data->window->img.ptr);
	return (0);
}

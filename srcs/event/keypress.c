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
#include <stdio.h>
#include "mlx.h"
#include "render.h"

void display_data(t_data *data);

t_data	*move_player(t_data *data)
{
	t_coor	pos;
	// printf("walk dir x: %d\n", data->player->walk_dir.x);
	// printf("walk dir y: %d\n", data->player->walk_dir.y);
	pos = data->player->pos;
	pos.x += data->player->walk_dir.x;
	pos.y += data->player->walk_dir.y;
	if (pos.x < 0)
		pos.x = 0;
	if (pos.x > data->map->size.width)
		pos.x = data->map->size.width;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > data->map->size.height)
		pos.y = data->map->size.height;
	if (data->map->matrix[pos.y][pos.x] != MAP_WALL)
		data->player->pos = pos;
	return (data);
}

int	keypress(int key, t_data *data)
{
	// mlx_destroy_image(data->window->mlx_ptr, data->window->img.ptr);
	data->mv_count += 1;
	printf("number of movements: %d \n", data->mv_count);
	if (key == KEY_Z)
		data->player->walk_dir.y = -1;
	if (key == KEY_S)
		data->player->walk_dir.y = +1;
	if (key == KEY_D)
		data->player->walk_dir.x = +1;
	if (key == KEY_Q)
		data->player->walk_dir.x = -1;
	
	data = move_player(data);
	
	data->window->img.ptr = mlx_new_image(data->window->mlx_ptr, data->window->size.width, data->window->size.height);
		data->window->img.data =(int *)mlx_get_data_addr(data->window->img.ptr, &data->window->img.bpp, &data->window->img.line_length, &data->window->img.endian);

	render_map(*data->window, *data->map, *data);

	// render player
	if (data->player->pos.x < data->window->size.width &&
		data->player->pos.y < data->window->size.height)
	{
		t_coor pos;

		pos.x = data->player->pos.x * data->tile_size.width + data->offset.x;
		pos.y = data->player->pos.y * data->tile_size.height + data->offset.y;
		render_rectangle(*data->window, pos, data->tile_size, 0xAAAAFF);
	}
	// printf("ok\n");
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->mlx_win, data->window->img.ptr, 0, 0);
	// mlx_destroy_image(data->window->mlx_ptr, data->window->img.ptr);
	return (0);
}

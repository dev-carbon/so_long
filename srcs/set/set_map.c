/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:31:28 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 03:58:58 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

static void	set_map_size(t_data *data)
{
	t_rows	*buff;

	buff = data->rows;
	data->map->size.width = data->rows->len;
	data->map->size.height = 0;
	while (buff)
	{
		data->map->size.height += 1;
		buff = buff->next;
	}
}

static t_data	*fill_matrix(t_data *data)
{
	t_coor	p;
	t_rows	*buff;

	buff = data->rows;
	p.y = 0;
	while (buff != NULL)
	{
		p.x = -1;
		while (buff->line[++p.x] != '\0')
		{
			if (buff->line[p.x] == '0')
				*(*(data->map->matrix + p.y) + p.x) = MAP_SPACE;
			if (buff->line[p.x] == '1')
				*(*(data->map->matrix + p.y) + p.x) = MAP_WALL;
			if (buff->line[p.x] == 'C')
				*(*(data->map->matrix + p.y) + p.x) = MAP_COLLECTIBLE;
			if (buff->line[p.x] == 'P')
				*(*(data->map->matrix + p.y) + p.x) = MAP_SPACE;
			if (buff->line[p.x] == 'E')
				*(*(data->map->matrix + p.y) + p.x) = MAP_EXIT;
		}
		buff = buff->next;
		p.y++;
	}
	return (data);
}

static int	**cpy_matrix(t_data *data)
{
	int	x;
	int	y;
	int	**cpy;

	cpy = (int **)malloc(sizeof(int *) * data->map->size.height);
	if (data->map->matrix == NULL)
		quit("malloc() top matrix copy pointer\n", 1, data);
	y = -1;
	while (++y < data->map->size.height)
	{
		*(cpy + y) = (int *)malloc(sizeof(int) * data->map->size.width);
		if (*(cpy + y) == NULL)
			quit("malloc() matrix line\n", EXIT_FAILURE, data);
	}
	y = -1;
	while (++y < data->map->size.height)
	{
		x = -1;
		while (++x < data->map->size.width)
			cpy[y][x] = data->map->matrix[y][x];
	}
	return (cpy);
}

t_data	*set_map(t_data *data)
{
	int		**cpy;

	if (data->map == NULL)
		init_map(data);
	set_map_size(data);
	if (data->map->matrix == 0)
		init_matrix(data);
	fill_matrix(data);
	cpy = cpy_matrix(data);
	if (!is_valid_matrix(data->config->start_pos.x,
			data->config->start_pos.y, cpy, data->map->size))
	{
		destroy_matrix(cpy, data->map->size);
		quit("map is not bordered.\n", EXIT_FAILURE, data);
	}
	destroy_rows(data);
	destroy_matrix(cpy, data->map->size);
	return (data);
}

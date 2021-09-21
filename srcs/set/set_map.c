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

t_data	*set_map(t_data *data)
{
	int		y;

	if (data->map == NULL)
		init_map(data);
	set_map_size(data);
	data->map->matrix = (int **)malloc(sizeof(int *) * data->map->size.height);
	if (data->map->matrix == NULL)
		quit("Unable to allocate sufficient memory for map\n", 1, data);
	y = -1;
	while (++y < data->map->size.height)
	{
		*(data->map->matrix + y) = (int *)malloc(sizeof(int)
				* data->map->size.width);
		if (*(data->map->matrix + y) == NULL)
			quit("Unable to allocate enougth memory for map\n", 1, data);
	}
	fill_matrix(data);
	return (data);
}

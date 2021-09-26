/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:47:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 04:47:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_matrix(t_data *data)
{
	int	y;

	data->map->matrix = (int **)malloc(sizeof(int *) * data->map->size.height);
	if (data->map->matrix == NULL)
		quit("malloc() top matrix pointer\n", 1, data);
	y = -1;
	while (++y < data->map->size.height)
	{
		*(data->map->matrix + y) = (int *)malloc(sizeof(int)
				* data->map->size.width);
		if (*(data->map->matrix + y) == NULL)
			quit("malloc() matrix line\n", 1, data);
	}
	return (data);
}

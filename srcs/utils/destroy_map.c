/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:49 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:18:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_map(t_data *data)
{
	int	y;

	if (data->map != NULL)
	{
		y = -1;
		while (++y < data->map->size.height)
			free(data->map->matrix[y]);
		free(data->map);
		data->map = NULL;
	}
}

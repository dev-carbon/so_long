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
	if (data->map != NULL)
	{
		destroy_matrix(data->map->matrix, data->map->size);
		free(data->map);
		data->map = NULL;
	}
}

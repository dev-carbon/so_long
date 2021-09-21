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

void	destroy_map(t_map *map)
{
	int	y;

	if (map != NULL)
	{
		y = -1;
		while (++y < map->size.height)
			free(*(map->matrix + y));
		free(map);
		map = NULL;
	}
}

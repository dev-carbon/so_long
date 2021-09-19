/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:09:10 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 16:09:21 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_map(int x, int y, int **grid, t_map map)
{
	if (x < 0 || x >= map.size.width
		|| y < 0 || y >= map.size.height)
		return (0);
	if (*(*(grid + y) + x) == MAP_WITNESS
		|| *(*(grid + y) + x) == MAP_EXIT
		|| *(*(grid + y) + x) == MAP_WALL)
		return (1);
	if (*(*(grid + y) + x) == MAP_SPACE
		|| *(*(grid + y) + x) == MAP_COLLECTIBLE
		|| *(*(grid + y) + x) == MAP_PLAYER
		|| *(*(grid + y) + x) == MAP_EXIT)
		*(*(grid + y) + x) = MAP_WITNESS;
	if (!is_valid_map(x + 1, y, grid, map))
		return (0);
	if (!is_valid_map(x - 1, y, grid, map))
		return (0);
	if (!is_valid_map(x, y + 1, grid, map))
		return (0);
	if (!is_valid_map(x, y - 1, grid, map))
		return (0);
	return (1);
}

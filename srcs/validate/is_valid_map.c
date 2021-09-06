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
	if (x < 0 || x >= map.size.width ||
		y < 0 || y >= map.size.height ||
		*(*(grid + y) + x) == MAP_UNKNOW)
		return (0);
	if (*(*(grid + y) + x) == 4 || *(*(grid + y) + x) == 1 ||
		*(*(grid + y) + x) == 6)
		return (1);
	if (*(*(grid + y) + x) == 0 || *(*(grid + y) + x) == 3 ||
		*(*(grid + y) + x) == 2)
		*(*(grid + y) + x) = 4;
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


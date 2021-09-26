/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:09:10 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 05:02:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_matrix(int x, int y, int **grid, t_size size)
{
	if (x < 0 || x >= size.width
		|| y < 0 || y >= size.height)
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
	if (!is_valid_matrix(x + 1, y, grid, size))
		return (0);
	if (!is_valid_matrix(x - 1, y, grid, size))
		return (0);
	if (!is_valid_matrix(x, y + 1, grid, size))
		return (0);
	if (!is_valid_matrix(x, y - 1, grid, size))
		return (0);
	return (1);
}

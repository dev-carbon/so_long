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
#include <stdio.h>

// void display_matrix(int **matrix, t_size size)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < size.height)
// 	{
// 		x = -1;
// 		while (++x < size.width)
// 			printf("%d ", matrix[y][x]);
// 		printf("\n");
// 	}
// }

int	is_valid_map(int x, int y, int **grid, t_map map)
{
	// si on depasse les bornes de la carte
	if (x < 0 || x >= map.size.width ||
		y < 0 || y >= map.size.height)
		return (0);
	if (*(*(grid + y) + x) == MAP_WITNESS ||
		*(*(grid + y) + x) == MAP_EXIT ||
		*(*(grid + y) + x) == MAP_WALL)
		return (1);
	if (*(*(grid + y) + x) == MAP_SPACE ||
		*(*(grid + y) + x) == MAP_COLLECTIBLE ||
		*(*(grid + y) + x) == MAP_EXIT)
		*(*(grid + y) + x) = MAP_WITNESS;
	//display_matrix(grid, map.size);
	//printf("\n\n");
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


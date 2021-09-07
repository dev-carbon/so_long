/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:31:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/06 09:31:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	display_data(t_data *data)
{
	int x;
	int	y;

	printf("\n\n*** CURRENT POSITIONS ***\n");
	printf("player: x = %d; y = %d\n", data->player->pos.x, data->player->pos.y);
	// printf("exit: x = %d; y = %d\n", data->exit_pos.x, data->exit_pos.y);
	// printf("\n\n*** COLLECTIBLES ***\n");
	// printf("num collectiblex: %d\n", data->num_collectibles);
	printf("\n\n*** SIZES ***\n");
	printf("map size: w = %d; h = %d\n", data->map->size.width, data->map->size.	height);
	// printf("\n\n*** MATRIX ***\n\n");
	// y = -1;
	// while (++y < data->map->size.height)
	// {
	// 	x = -1;
	// 	while (++x < data->map->size.width)
	// 		printf("%d ", data->map->matrix[y][x]);
	// 	printf("\n");
	// }
	// printf("\n\n");
}


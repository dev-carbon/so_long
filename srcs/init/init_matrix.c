/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:23:46 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:23:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_matrix(t_data *data)
{
	int	**cmatrix;
	int	i;
	int j;

	cmatrix = (int **)malloc(sizeof(int *) * data->map->size.height);
	if (!cmatrix)
		close_game("unable to allocate memory for map\n", EXIT_FAILURE, data);
	j = -1;
	while (++j < data->map->size.height)
	{
		*(cmatrix + j) = (int *)malloc(sizeof(int) * data->map->size.width);	
		if (!(*(cmatrix + j)))
			close_game("unable to allocate memory for map\n", EXIT_FAILURE, data);
	}
	j = -1;
	while (++j < data->map->size.height)
	{
		i = -1;
		while (++i < data->map->size.width)
			cmatrix[j][i] = data->map->matrix[j][i];
	}
	if(!is_valid_map(data->start_pos.x, data->start_pos.y, cmatrix, *data->map))
		close_game("The matrix is not correctly bordered\n", EXIT_FAILURE, data);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:49:49 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 15:49:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	escape(t_coor pos, t_data *data)
{
	data->map->matrix[pos.y][pos.x] = MAP_SPACE;
	quit("", EXIT_SUCCESS, data);
}

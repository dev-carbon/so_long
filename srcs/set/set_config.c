/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:00:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:00:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_data	*set_config(t_data *data)
{
	data->config->tile_size.width = TILE_SIZE;
	data->config->tile_size.height = TILE_SIZE;
	return (data);
}

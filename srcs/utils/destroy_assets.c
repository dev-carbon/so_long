/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 03:09:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 03:09:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_assets(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (data->assets[i].img.ptr)
			mlx_destroy_image(data->window->mlx_ptr, data->assets[i].img.ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 03:59:33 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 03:59:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_assets(t_data *data)
{
	int	i;

	i = -1;
	while (++i < NUM_ASSETS)
		data->assets[i].img.ptr = NULL;
	return (data);
}

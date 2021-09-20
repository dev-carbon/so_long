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

t_data	*set_config(t_data *data, char c, t_coor pos)
{
	if (c == 'C')
		data->config->num_collectibles += 1;
	if (c == 'P')
		data->config->start_pos = pos;
	if (c == 'E')
		data->config->exit_pos = pos;
	return (data);
}

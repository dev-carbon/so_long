/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:16:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:16:13 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drivers.h"

t_data	*setup(t_data *data)
{
	set_window(data);
	set_config(data);
	set_map(data);
	set_player(data);
	set_textures(data);
	return (data);
}

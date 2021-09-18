/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:29:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/10 17:29:04 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*set_window(t_data *data)
{
	data->window->mlx_ptr = mlx_init();
	data->window->size.width = WIN_WIDTH;
	data->window->size.height = WIN_HEIGHT;
	data->window->mlx_win = mlx_new_window(data->window->mlx_ptr, data->window->size.width, data->window->size.height, APP_NAME);
	return (data);
}

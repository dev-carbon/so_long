/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_window(t_data *data)
{
	if (data->window != NULL)
	{
		if (data->window->img.ptr)
			mlx_destroy_image(data->window->mlx_ptr, data->window->img.ptr);
		if (data->window->mlx_win)
			mlx_destroy_window(data->window->mlx_ptr, data->window->mlx_win);
		if (data->window->mlx_ptr)
			mlx_destroy_display(data->window->mlx_ptr);
		if (data->window)
			free(data->window);
		data->window = NULL;
	}
}

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

void	destroy_window(t_window *window)
{
	if (window != NULL)
	{
		mlx_destroy_image(window->mlx_ptr, window->img.ptr);
		mlx_destroy_window(window->mlx_ptr, window->mlx_win);
		free(window);
		window = NULL;
	}
}

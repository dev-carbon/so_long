/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:54:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/06 14:54:21 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_rectangle(t_window win, t_coor start, t_size size, int color)
{
	int		x;
	int		y;

	if (start.x < 0 || start.y < 0)
		return ;
	y = start.y - 1;
	while (++y <= size.height + start.y)
	{
		x = start.x - 1;
		while (++x <= size.width + start.x)
			win.img.data[(y * win.size.width) + x] = color;
	}
}

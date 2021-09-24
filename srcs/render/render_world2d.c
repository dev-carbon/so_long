/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:59:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/08 13:59:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_world2d(t_window win, t_map map, t_data data)
{
	render_map(win, map, data);
	render_collectibles(win, data.config->collectibles, data);
	render_exits(win, data.config->exits, data);
	render_player(win, *data.player, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:54:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/06 14:56:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "so_long.h"

void	render_world2d(t_window win, t_map map, t_data data);
void	render_player(t_window win, t_player player, t_data data);
void	render_collectibles(t_window win, t_collectible *c, t_data data);
void	render_exits(t_window win, t_exit *exits, t_data data);
void	render_map(t_window win, t_map map, t_data data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:27:26 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 12:45:24 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

int			close_game(char *message, int status, t_data *data);
void		display_data(t_data *data);
void		display_coordinates(t_coor coor);
void		display_size(t_size size);
int			is_wall(t_coor pos, t_map map, t_size tile_size);
int			is_space(t_coor pos, t_map map, t_size tile_size);
int			is_collectible(t_coor pos, t_map map, t_size tile_size);
int			is_player(t_coor pos, t_map map, t_size tile_size);
int			is_exit(t_coor pos, t_map map, t_size tile_size);
t_texture	get_texture(t_coor pos, t_map map, t_data data);
t_coor		get_texel(t_coor pos, t_size texture_size, t_size tile_size);

#endif

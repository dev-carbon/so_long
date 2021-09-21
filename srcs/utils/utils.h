/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:27:26 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:02:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

void		display_rows(t_rows *rows);
void		display_data(t_data *data);
void		display_coordinates(t_coor coor);
void		display_size(t_size size);
void    	write_score_fd(int items, int moves, int fd);
void	    destroy_window(t_window *window);
void		destroy_rows(t_rows *rows);
void	    destroy_map(t_map *map);
void	    destroy_config(t_config *config);
void	    destroy_player(t_player *player);
int			is_wall(t_coor pos, t_map map, t_size tile_size);
int			is_space(t_coor pos, t_map map, t_size tile_size);
int			is_collectible(t_coor pos, t_map map, t_size tile_size);
int			is_player(t_coor pos, t_map map, t_size tile_size);
int			is_exit(t_coor pos, t_map map, t_size tile_size);
t_asset     get_asset(t_coor pos, t_map map, t_data data);
t_coor		get_texel(t_coor pos, t_size asset_size, t_size tile_size);

#endif

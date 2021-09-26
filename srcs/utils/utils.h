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

void		write_score_fd(int items, int moves, int fd);
void		destroy_assets(t_data *data);
void		destroy_window(t_data *data);
void		destroy_rows(t_data *data);
void		destroy_map(t_data *data);
void		destroy_config(t_data *data);
void		destroy_player(t_data *data);
int			is_wall(t_coor pos, t_map map, t_size tile_size);
int			is_space(t_coor pos, t_map map, t_size tile_size);
int			is_collectible(t_coor pos, t_map map, t_size tile_size);
int			is_player(t_coor pos, t_map map, t_size tile_size);
int			is_exit(t_coor pos, t_map map, t_size tile_size);
int			close_window(t_data *data);
t_asset		get_asset(t_coor pos, t_map map, t_data data);
t_coor		get_texel(t_coor pos, t_size asset_size, t_size tile_size);

#endif

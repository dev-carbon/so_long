/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:47:08 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 00:47:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_rows
{
	char			*line;
	int				len;
	struct s_rows	*next;
}	t_rows;

typedef struct s_collectibles
{
	int						is_collected;
	t_coor					pos;
	struct s_collectibles	*next;
}	t_collectibles;

typedef struct s_map {
	t_size	size;
	int		**matrix;
}	t_map;

typedef struct s_image
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	img;
	t_size	size;
}	t_window;

typedef struct s_player
{
	t_coor	pos;
	t_coor	walk_dir;
	int		move;
	int		collected;
}	t_player;

typedef struct s_asset
{
	char	*path;
	t_size	size;
	t_image	img;
}	t_asset;

typedef struct s_config
{
	int		num_collectibles;
	t_collectibles	*collectibles;
	t_size	tile_size;
	t_coor	start_pos;
	t_coor	exit_pos;
}	t_config;

typedef struct s_data
{
	int			fd;
	int			ret;
	char		*line;
	t_rows		*rows;
	t_config	*config;
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_asset	assets[5];
}	t_data;

#endif

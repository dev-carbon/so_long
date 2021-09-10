/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:48:48 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 10:48:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "utils.h"

# define APP_NAME "so_long"

# define MAP_SPACE 0
# define MAP_WALL 1
# define MAP_COLLECTIBLE 2
# define MAP_PLAYER 3
# define MAP_EXIT 4
# define MAP_WITNESS 5

# define TEXTURE_WALL 0
# define TEXTURE_WATER 1
# define TEXTURE_FISH 2
# define TEXTURE_DOLPHIN 3
# define TEXTURE_EXIT 4

# define RED 0xAA0000
# define GREEN 0x00AA00
# define BLUE 0x0000AA

# define WIN_WIDTH 980
# define WIN_HEIGHT 780

typedef struct s_coor
{
	int  x;
	int  y;
}   t_coor;

typedef struct s_size
{
	int width;
	int height;
}   t_size;

typedef struct s_rows
{
	char    *line;
	int     len;
	struct s_rows *next;
}   t_rows;

typedef struct s_map {
	t_size	size;
	int		**matrix;
}   t_map;

typedef struct s_image
{
	void    *ptr;
	int     *data;
	int     bpp;
	int     line_length;
	int     endian;
}   t_image;

typedef struct s_window
{
	void    *mlx_ptr;
	void    *mlx_win;
	t_image img;
	t_size  size;
}   t_window;

typedef struct s_player
{
	t_coor  pos;
	t_coor	walk_dir;
}   t_player;

typedef struct	s_texture
{
	char	*path;
	t_size	size;
	t_image	img;
}	t_texture;

typedef struct s_config
{
	int			num_collectibles;
	t_size		screen_size;
	t_size		tile_size;
	t_coor		offset;
	t_coor		start_pos;
	t_coor		exit_pos;
}	t_config;

typedef struct s_data 
{
	int			fd;
	int			ret;
	char		*line;
	char		**split;
	t_rows		*rows;
	t_config	*config;
	t_window    *window;
	t_texture	textures[5];
	t_map		*map;
	t_player    *player;
}	t_data;

#endif

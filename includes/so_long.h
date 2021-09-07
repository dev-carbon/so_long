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

# define APP_NAME "so_long"

# define MAP_SPACE 0
# define MAP_WALL 1
# define MAP_COLLECTIBLE 2
# define MAP_EXIT 3
# define MAP_WITNESS 4

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

typedef struct s_data 
{
	int			fd;
	int			ret;
	char		*line;
	char		**split;
	int			num_collectibles;
	int			mv_count;
	t_size		tile_size;
	t_coor		offset;
	t_coor		start_pos;
	t_coor		exit_pos;
	t_rows		*rows;
	t_map		*map;
	t_player    *player;
	t_window    *window;
}	t_data;

#endif

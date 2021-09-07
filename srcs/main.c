/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:30:30 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/03 19:30:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "validate.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utils.h>
#include "mlx.h"
#include "event.h"
#include "render.h"

static t_data	*init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->window = (t_window *)malloc(sizeof(t_window));
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->size.width = 0;
	data->map->size.height = 0;
	data->player = (t_player *)malloc(sizeof(t_player));
	data->player->pos.x = -1;
	data->player->pos.y = -1;
	data->player->walk_dir.x = 0;
	data->player->walk_dir.y = 0;
	data->offset.x = 0;
	data->offset.y = 0;
	data->num_collectibles = 0;
	data->exit_pos.x = -1;
	data->exit_pos.y = -1;
	data->start_pos.x = -1;
	data->start_pos.y = -1;
	data->rows = NULL;
	data->mv_count = 0;
	return (data);
}

static t_rows	*add_rows(char *line, t_data *data)
{
	t_rows	*new;
	t_rows	*last;

	new = (t_rows *)malloc(sizeof(t_rows));
	new->line = line;
	new->len = ft_strlen(line);
	new->next = NULL;
	if (data->rows == NULL)
		data->rows = new;
	else {
		last = data->rows;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (data->rows);
}

static t_data	*set_config(char c,t_coor pos, t_data *data) {
	if (c == 'C')
		data->num_collectibles += 1;
	if (c == 'P')
		data->start_pos = pos;
	if (c == 'E')
		data->exit_pos = pos;
	return (data);
}

void display_matrix(int **matrix, t_size size)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size.height)
	{
		x = -1;
		while (++x < size.width)
			printf("%d ", matrix[y][x]);
		printf("\n");
	}
}

static t_data	*parse(const char *filename, t_data *data)
{
	// getting rows
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		close_game("Unable to open map file.\n", EXIT_FAILURE, data);
	while (1)
	{
		data->ret = get_next_line(data->fd, &data->line);
		add_rows(data->line, data);
		if (data->ret == -1 || data->ret == 0)
			break;
	}
	// validating rows
	t_coor	pos;
	t_rows	*buff;

	buff = data->rows;
	pos.y = -1;
	while (buff != NULL)
	{
		// printf("-> %s\n", buff->line);
		// check bad character
		pos.x = -1;
		pos.y++;
		while (buff->line[(int)++pos.x])
		{
			if (buff->line[(int)pos.x] != '0' &&
				buff->line[(int)pos.x] != '1' &&
				buff->line[(int)pos.x] != 'P' &&
				buff->line[(int)pos.x] != 'C' &&
				buff->line[(int)pos.x] != 'E')
				close_game("Bad map character.\n", EXIT_FAILURE, data);
			else
				set_config(buff->line[(int)pos.x], pos, data);
		}
		
		// check same lenght
		if (buff->next != NULL && buff->len != buff->next->len)
			close_game("The map is not rectangular.\n", EXIT_FAILURE, data);
		buff = buff->next;
	}
	// check if map has player, collectibles and exit
	if (data->start_pos.x == -1 && data->start_pos.y == -1)
		close_game("There is no player in the map.\n", EXIT_FAILURE, data);
	if (data->exit_pos.x == -1 && data->exit_pos.y == -1)
		close_game("There is no exit in the map.\n", EXIT_FAILURE, data);
	if (data->num_collectibles == 0)
		close_game("There is no collectibles in the map.\n",
			EXIT_FAILURE, data);

	// init map sizex
	buff = data->rows;
	data->map->size.width = data->rows->len;
	while (buff)
	{
		data->map->size.height += 1;
		buff = buff->next;
	}

	// init matrix
	int y;

	y = -1;
	data->map->matrix = (int **)malloc(sizeof(int *) * data->map->size.height);
	while (++y < data->map->size.height)
	{
		*(data->map->matrix + y) = (int *)malloc(sizeof(int) * data->map->size.width);
	}
	
	t_coor	p;
	char	c;
	// fill matrix
	buff = data->rows;
	p.y = 0;
	while (buff != NULL)
	{
		p.x = -1;
		while ((c = buff->line[(int)++p.x]) != '\0')
		{
			if (c == '0')
				*(*(data->map->matrix + (int)p.y) + (int)p.x) = MAP_SPACE;
			if (c == '1')
				*(*(data->map->matrix + (int)p.y) + (int)p.x) = MAP_WALL;
			if (c == 'C')
				*(*(data->map->matrix + (int)p.y) + (int)p.x) = MAP_COLLECTIBLE;
			if (c == 'P')
				*(*(data->map->matrix + (int)p.y) + (int)p.x) = MAP_SPACE;
			if (c == 'E')
				*(*(data->map->matrix + (int)p.y) + (int)p.x) = MAP_EXIT;
		}
		buff = buff->next;
		p.y++;
	}
	return (data);
}

static t_data	*init_matrix(t_data *data)
{
	int	**cmatrix;
	int	i;
	int j;

	cmatrix = (int **)malloc(sizeof(int *) * data->map->size.height);
	j = -1;
	while (++j < data->map->size.height)
		*(cmatrix + j) = (int *)malloc(sizeof(int) * data->map->size.width);	
	j = -1;
	while (++j < data->map->size.height)
	{
		i = -1;
		while (++i < data->map->size.width)
			cmatrix[j][i] = data->map->matrix[j][i];
	}
	// check if matrix is correctly bordered
	if(!is_valid_map(data->start_pos.x, data->start_pos.y, cmatrix, *data->map))
		close_game("The matrix is not correctly bordered\n", EXIT_FAILURE, data);
	// display_matrix(cmatrix, data->map->size);
	return (data);
}


int	main(const int argc, const char *argv[])
{
	t_data	*data;

	if (is_valid_args(argc, argv) && (data = init(data)))
	{
		parse(argv[1], data);
		init_matrix(data);

		// dislpay matrix in mlx window.
		data->window->size.width = 980;
		data->window->size.height = 780;
		data->window->mlx_ptr = mlx_init();
		data->window->mlx_win = mlx_new_window(data->window->mlx_ptr, data->window->size.width, data->window->size.height, APP_NAME);

		data->window->img.ptr = mlx_new_image(data->window->mlx_ptr, data->window->size.width, data->window->size.height);
		data->window->img.data =(int *)mlx_get_data_addr(data->window->img.ptr, &data->window->img.bpp, &data->window->img.line_length, &data->window->img.endian);

		int min = ft_min(data->window->size.width, data->window->size.height);
		int max = ft_max(data->map->size.width, data->map->size.height);
		data->tile_size.width = min / max;
		data->tile_size.height = min / max;

		data->offset.x = (data->window->size.width - data->map->size.width * data->tile_size.width) / 2;
		data->offset.y = (data->window->size.height - data->map->size.height * data->tile_size.height) / 2;

		// printf("ts: %d\n", tile_size);
		render_map(*data->window, *data->map, *data);
		data->player->pos = data->start_pos;
		// display_data(data);

		// render player
		data->start_pos.x = data->start_pos.x * data->tile_size.width + data->offset.x;
		data->start_pos.y = data->start_pos.y * data->tile_size.height + data->offset.y;
		render_rectangle(*data->window, data->start_pos, data->tile_size, 0xAAAAFF);

		mlx_put_image_to_window(data->window->mlx_ptr, data->window->mlx_win, data->window->img.ptr, 0, 0);

		mlx_hook(data->window->mlx_win, 2, 1L << 0, &keypress, data);
		mlx_hook(data->window->mlx_win, 3, 1L << 1, &keyrelease, data);
		mlx_hook(data->window->mlx_win, 33, 1L << 17, &close_game, data);
		//mlx_loop_hook(data->window->mlx_ptr, &so_long_loop, data);
		mlx_loop(data->window->mlx_ptr);

	}
	return (0);
}

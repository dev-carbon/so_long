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

static t_data	*init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->num_collectibles = 0;
	data->exit_pos.x = -1;
	data->exit_pos.y = -1;
	data->start_pos.x = -1;
	data->start_pos.y = -1;
	data->rows = NULL;
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

	pos.y = -1; 
	while (data->rows != NULL)
	{
		printf("-> %s\n", data->rows->line);
		// check bad character
		pos.x = -1;
		pos.y++;
		while (data->rows->line[(int)++pos.x])
		{
			if (data->rows->line[(int)pos.x] != '0' &&
				data->rows->line[(int)pos.x] != '1' &&
				data->rows->line[(int)pos.x] != 'P' &&
				data->rows->line[(int)pos.x] != 'C' &&
				data->rows->line[(int)pos.x] != 'E')
				close_game("Bad map character.\n", EXIT_FAILURE, data);
			else
				set_config(data->rows->line[(int)pos.x], pos, data);
		}
		
		// check same lenght
		if (data->rows->next != NULL && data->rows->len != data->rows->next->len)
			close_game("The map is not rectangular.\n", EXIT_FAILURE, data);
		data->rows = data->rows->next;
	}
	// check if map has player, collectibles and exit
	if (data->start_pos.x == -1 && data->start_pos.y == -1)
		close_game("There is no player in the map.\n", EXIT_FAILURE, data);
	if (data->exit_pos.x == -1 && data->exit_pos.y == -1)
		close_game("There is no exit in the map.\n", EXIT_FAILURE, data);
	
	// check if map is correctly bordered
	return (data);
}

int	main(const int argc, const char *argv[])
{
	t_data	*data;

	if (is_valid_args(argc, argv) && (data = init(data)))
	{
		data = parse(argv[1], data);
		printf("start pos x = %f; y = %f\n", data->start_pos.x, data->start_pos.y);
		close_game("bye.\n", EXIT_SUCCESS, data);
	}
	return (0);
}

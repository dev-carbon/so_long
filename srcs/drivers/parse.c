/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:16:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/29 06:30:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drivers.h"

static t_rows	*add_row(char *line, t_data *data)
{
	t_rows	*new;
	t_rows	*last;

	new = (t_rows *)malloc(sizeof(t_rows));
	if (new == NULL)
		quit("malloc() row\n", 1, data);
	new->line = ft_strdup(line);
	new->len = ft_strlen(line);
	new->next = NULL;
	if (data->rows == NULL)
		data->rows = new;
	else
	{
		last = data->rows;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (data->rows);
}

static t_data	*read_rows(t_data *data)
{
	while (1)
	{
		data->ret = get_next_line(data->fd, &data->line);
		if (data->ret == -1)
		{
			free(data->line);
			break ;
		}
		add_row(data->line, data);
		free(data->line);
		if (data->ret == 0)
			break ;
	}
	return (data);
}

static t_data	*get_map_elements(t_data *data)
{
	t_coor	pos;
	t_rows	*buff;

	pos.y = 0;
	buff = data->rows;
	while (buff)
	{
		pos.x = -1;
		while (buff->line[++pos.x] != '\0')
			set_config(data, buff->line[pos.x], pos);
		buff = buff->next;
		pos.y++;
	}
	return (data);
}

static int	check_errors(t_data *data)
{
	if (data->config->start_pos.x == -1 && data->config->start_pos.y == -1)
		quit("No player in the map.\n", 1, data);
	if (data->config->num_players > 1)
		quit("Multiple start positions.\n", 1, data);
	if (data->config->num_exits == 0)
		quit("No exit in the map.\n", 1, data);
	if (data->config->num_collectibles == 0)
		quit("No collectibles in the map.\n", 1, data);
	return (0);
}

t_data	*parse(const char *filename, t_data *data)
{
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		quit("open() file.\n", EXIT_FAILURE, data);
	read_rows(data);
	if (data->rows == NULL)
		quit("read() file.\n", EXIT_FAILURE, data);
	if (is_valid_rows(data))
		get_map_elements(data);
	check_errors(data);
	close(fd);
	return (data);
}

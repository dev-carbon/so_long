/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:16:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:16:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drivers.h"

static t_rows	*add_rows(char *line, t_data *data)
{
	t_rows	*new;
	t_rows	*last;

	new = (t_rows *)malloc(sizeof(t_rows));
	if (new == NULL)
		close_game("Unable to allocate enougth memory\n", 1, data);
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

t_data	*parse(const char *filename, t_data *data)
{
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		close_game("Unable to open map file.\n", EXIT_FAILURE, data);
	while (1)
	{
		data->ret = get_next_line(data->fd, &data->line);
		add_rows(data->line, data);
		free(data->line);
		if (data->ret == -1 || data->ret == 0)
			break ;
	}
	if (is_valid_rows(data))
		;
	get_map_elements(data);
	if (data->config->start_pos.x == -1 && data->config->start_pos.y == -1)
		close_game("There is no player in the map.\n", EXIT_FAILURE, data);
	if (data->config->exit_pos.x == -1 && data->config->exit_pos.y == -1)
		close_game("There is no exit in the map.\n", EXIT_FAILURE, data);
	if (data->config->num_collectibles == 0)
		close_game("There is no collectibles in the map.\n",
			EXIT_FAILURE, data);
	return (data);
}

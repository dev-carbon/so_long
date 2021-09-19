/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:42:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 11:42:57 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	void	destroy_rows(t_rows *rows)
{
	t_rows	*current;

	while (rows != NULL)
	{
		current = rows;
		rows = rows->next;
		free(current->line);
		free(current);
		current = NULL;
	}
	free(rows);
	rows = NULL;
}

static void	destroy_map(t_map *map)
{
	int	y;

	if (map != NULL)
	{
		y = -1;
		while (++y < map->size.height)
			free(*(map->matrix + y));
		free(map->matrix);
		free(map);
		map = NULL;
	}
}

static void	destroy_window(t_window *window)
{
	if (window != NULL)
	{
		mlx_destroy_image(window->mlx_ptr, window->img.ptr);
		mlx_destroy_window(window->mlx_ptr, window->mlx_win);
		free(window->mlx_ptr);
		free(window);
		window = NULL;
	}
}

static void	write_message(char *message, int status)
{
	if (status == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, message, ft_strlen(message));
	}
	if (status == EXIT_SUCCESS)
	{
		write(STDOUT_FILENO, "Success\n", 8);
		write(STDOUT_FILENO, message, ft_strlen(message));
	}
}

int	close_game(char *message, int status, t_data *data)
{
	write_message(message, status);
	if (data != NULL)
	{
		printf("player collected: %d collectible(s)\n", data->player->collected);
		destroy_rows(data->rows);
		destroy_map(data->map);
		destroy_window(data->window);
		if (data->config != NULL)
		{
			free(data->config);
			data->config = NULL;
		}
		if (data->player != NULL)
		{
			free(data->player);
			data->player = NULL;
		}
		free(data);
		data = NULL;
	}
	exit(status);
}

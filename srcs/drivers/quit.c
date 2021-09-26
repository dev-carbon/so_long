/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:42:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 11:42:57 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	destroy_data(t_data *data)
{
	if (data != NULL)
	{
		destroy_rows(data);
		destroy_config(data);
		destroy_assets(data);
		destroy_player(data);
		destroy_window(data);
		destroy_map(data);
		free(data);
		data = NULL;
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
		write(STDOUT_FILENO, message, ft_strlen(message));
}

int	quit(char *message, int status, t_data *data)
{
	destroy_data(data);
	write_message(message, status);
	exit(status);
}

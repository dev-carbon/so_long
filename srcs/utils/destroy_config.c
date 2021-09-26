/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:59 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:20:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	destroy_collectibles(t_data *data)
{
	t_collectible	*current;

	if (data->config->collectibles != NULL)
	{
		while (data->config->collectibles != NULL)
		{
			current = data->config->collectibles;
			data->config->collectibles = data->config->collectibles->next;
			free(current);
			current = NULL;
		}
		free(data->config->collectibles);
		data->config->collectibles = NULL;
	}
}

static void	destroy_exits(t_data *data)
{
	t_exit	*current;

	if (data->config->exits != NULL)
	{
		while (data->config->exits != NULL)
		{
			current = data->config->exits;
			data->config->exits = data->config->exits->next;
			free(current);
			current = NULL;
		}
		free(data->config->exits);
		data->config->exits = NULL;
	}
}

void	destroy_config(t_data *data)
{
	if (data->config != NULL)
	{
		destroy_collectibles(data);
		destroy_exits(data);
		free(data->config);
		data->config = NULL;
	}
}

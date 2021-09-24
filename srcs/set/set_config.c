/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:00:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:00:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

static	t_data	*add_collectible(t_coor pos, t_data *data)
{
	t_collectible	*new;
	t_collectible	*last;

	new = (t_collectible *)malloc(sizeof(t_collectible));
	if (!new)
		quit("Unable to allocate enougth memory for collectible", 1, data);
	new->pos = pos;
	new->is_collected = 0;
	new->next = NULL;
	if (data->config->collectibles == NULL)
		data->config->collectibles = new;
	else
	{
		last = data->config->collectibles;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	data->config->num_collectibles += 1;
	return (data);
}

static t_data	*add_exit(t_coor pos, t_data *data)
{
	t_exit	*new;
	t_exit	*last;

	new = (t_exit *)malloc(sizeof(t_exit));
	if (!new)
		quit("Unable to allocate memory for exit", 1, data);
	new->pos = pos;
	new->next = NULL;
	if (data->config->exits == NULL)
		data->config->exits = new;
	else
	{
		last = data->config->exits;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	data->config->num_exits += 1;
	return (data);
}

t_data	*set_config(t_data *data, char c, t_coor pos)
{
	if (data->config == NULL)
		init_config(data);
	if (c == 'C')
		add_collectible(pos, data);
	else if (c == 'P')
	{
		data->config->start_pos = pos;
		data->config->num_players += 1;
	}
	else if (c == 'E')
		add_exit(pos, data);
	return (data);
}

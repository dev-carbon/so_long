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
	t_collectibles	*new;
	t_collectibles	*last;

	new = (t_collectibles *)malloc(sizeof(t_collectibles));
	if (!new)
		close_game("Unable to allocate enougth memory for collectible", 1, data);
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

t_data	*set_config(t_data *data, char c, t_coor pos)
{
	if (c == 'C')
		add_collectible(pos, data);
	else if (c == 'P')
		data->config->start_pos = pos;
	else if (c == 'E')
		data->config->exit_pos = pos;
	return (data);
}

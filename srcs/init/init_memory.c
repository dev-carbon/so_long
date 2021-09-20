/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:57:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 14:57:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data	*init_memory(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, NULL);
	data->window = (t_window *)malloc(sizeof(t_window));
	if (data->window == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->config = (t_config *)malloc(sizeof(t_config));
	if (data->config == NULL)
		close_game("Unable to allocate sufficient memory\n", 1, data);
	data->rows = NULL;
	return (data);
}

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

t_data	*init_data(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		quit("Unable to init data\n", 1, NULL);
	data->map = NULL;
	data->config = NULL;
	data->window = NULL;
	data->player = NULL;
	data->rows = NULL;
	return (data);
}

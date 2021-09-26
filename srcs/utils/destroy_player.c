/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:20:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:20:13 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_player(t_data *data)
{
	if (data->player != NULL)
	{
		free(data->player);
		data->player = NULL;
	}
}

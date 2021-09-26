/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:53:00 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 01:53:07 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	close_window(t_data *data)
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
	exit(EXIT_SUCCESS);
}

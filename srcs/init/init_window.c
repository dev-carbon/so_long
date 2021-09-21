/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:50:33 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:50:34 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data  *init_window(t_data *data)
{
    data->window = (t_window *)malloc(sizeof(t_window));
	if (data->window == NULL)
		quit("Unable to init window\n", EXIT_FAILURE, data);
    return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:54:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/20 15:03:49 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drivers.h"

t_data  *initialize(t_data *data)
{
    data = init_memory(data);
	init_config(data);
	init_player(data);
    return (data);
}

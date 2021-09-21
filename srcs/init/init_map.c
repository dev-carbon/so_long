/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:41:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:41:24 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_data  *init_map(t_data *data)
{
    data->map = (t_map *)malloc(sizeof(t_map));
    if (data->map == NULL)
        quit("Unable to init map\n", EXIT_FAILURE, data);
    return (data);
}

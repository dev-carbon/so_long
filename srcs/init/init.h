/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:36:33 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 19:36:35 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "so_long.h"

t_data	*init_memory(t_data *data);
t_data	*init_config(t_data *data);
t_data	*init_player(t_data *data);

#endif

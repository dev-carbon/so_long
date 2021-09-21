/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drivers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:16:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 04:16:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRIVERS_H
# define DRIVERS_H

# include "so_long.h"

int 	start(t_data *data);
int     refresh(t_data *data);
int	    quit(char *message, int status, t_data *data);
t_data	*parse(const char *filename, t_data *data);
t_data	*setup(t_data *data);
t_data	*so_long(int key, t_data *data);

#endif

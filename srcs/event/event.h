/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:05:06 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/07 10:24:42 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "so_long.h"

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define KEY_Z 122
# define KEY_S 115
# define KEY_Q 113
# define KEY_D 100

int	keypress(int key, t_data *data);
int	keyrelease(int key, t_data *data);

#endif

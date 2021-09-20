/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:18:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 19:18:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENGINE_H
# define ENGINE_H

# include "so_long.h"

void    move(int key, t_coor pos, t_data *data);
t_data   *collect(t_coor pos, t_data *data);
void    escape(t_coor pos, t_data *data);

#endif

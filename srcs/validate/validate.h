/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:16:06 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 11:16:08 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "so_long.h"

int	is_valid_args(const int ac, const char **av);
int	is_valid_file_extension(const char *filename, const char *ext);
int	is_valid_matrix(int x, int y, int **grid, t_size size);
int	is_valid_rows(t_data *data);
int	is_valid_key(int key);

#endif

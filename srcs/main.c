/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:30:30 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/03 19:30:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(const int argc, const char *argv[])
{
	t_data	*data;

	if (is_valid_args(argc, argv) && (data = init(data)))
	{
		parse(argv[1], data);
		setup(data);
		display_data(data);
		run(data);
		mlx_hook(data->window->mlx_win, 2, 1L << 0, &keypress, data);
		mlx_hook(data->window->mlx_win, 3, 1L << 1, &keyrelease, data);
		mlx_hook(data->window->mlx_win, 33, 1L << 17, &close_game, data);
		mlx_loop(data->window->mlx_ptr);
	}
	return (0);
}

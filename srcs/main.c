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

	if (is_valid_args(argc, argv))
	{
		data = init_data(data);
		parse(argv[1], data);
		setup(data);
		start(data);
	}
	return (0);
}

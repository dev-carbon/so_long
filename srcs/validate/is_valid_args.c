/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:23:00 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 11:23:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_args(const int ac, const char **av)
{
	if (ac != 2)
		quit("Invalid number of arguments.\n", EXIT_FAILURE, NULL);
	if (!is_valid_file_extension(av[1], ".ber"))
		quit("Invalid file extension.\n", EXIT_FAILURE, NULL);
	return (1);
}

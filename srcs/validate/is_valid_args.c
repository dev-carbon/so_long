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
#include "utils.h"
#include <stdlib.h>

int is_valid_args(const int ac, const char **av)
{
    if (ac != 2)
        close_game("Invalid number of arguments.\n", EXIT_FAILURE, NULL);
    else if (!is_valid_file_extension(av[1], ".ber"))
        close_game("Invalid file extension.\n", EXIT_FAILURE, NULL);
    return (1);
}

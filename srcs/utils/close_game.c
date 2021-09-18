/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:42:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 11:42:57 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int close_game(char *message, int status, t_data *data)
{
    if (status == EXIT_FAILURE)
    {
        write(STDERR_FILENO, "Error\n", 6);
        write(STDERR_FILENO, message, ft_strlen(message));
    }
    if (status == EXIT_SUCCESS)
    {
        write(STDOUT_FILENO, "Success\n", 8);
        write(STDOUT_FILENO, message, ft_strlen(message));
    }
    if (data != NULL) {
        free(data);
        data  = NULL;
    }
    exit(status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:40:17 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/04 12:40:21 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "libft.h"
#include <stdio.h>

int is_valid_file_extension(const char *filename, const char *ext)
{
    int     len;
    int     index;

    len = ft_strlen(ext);
    index = ft_strlen(filename) - len;
    if (ft_strncmp(filename + index, ext, len) != 0) 
        return (0);
    return (1);
}

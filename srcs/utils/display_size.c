/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:46:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/09 12:46:58 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	display_size(t_size size)
{
	printf("x: %d; y: %d\n", size.width, size.height);
}
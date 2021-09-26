/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:52:53 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/26 04:56:07 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_matrix(int **matrix, t_size size)
{
	int	y;

	y = -1;
	while (++y < size.height)
		free(matrix[y]);
	free(matrix);
}

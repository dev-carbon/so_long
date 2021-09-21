/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:42:37 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/18 03:42:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_rows(t_data *data)
{
	t_coor	pos;
	t_rows	*buff;

	buff = data->rows;
	if (!buff)
		return (0);
	pos.y = -1;
	while (buff != NULL)
	{
		pos.x = -1;
		pos.y++;
		while (buff->line[++pos.x])
		{
			if (buff->line[pos.x] != '0' && buff->line[pos.x] != '1'
				&& buff->line[pos.x] != 'P' && buff->line[pos.x] != 'C'
				&& buff->line[pos.x] != 'E')
				quit("Bad map character.\n", EXIT_FAILURE, data);
		}
		if (buff->next != NULL && buff->len != buff->next->len)
			quit("The map is not rectangular.\n", EXIT_FAILURE, data);
		buff = buff->next;
	}
	return (1);
}

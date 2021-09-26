/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_data	*destroy_rows(t_data *data)
{
	t_rows	*current;

	if (data->rows != NULL)
	{
		while (data->rows != NULL)
		{
			current = data->rows;
			data->rows = data->rows->next;
			free(current->line);
			free(current);
		}
		free(data->rows);
		data->rows = NULL;
	}
	return (data);
}

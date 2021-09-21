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

void	destroy_rows(t_rows *rows)
{
	t_rows	*current;

	if (rows != NULL)
	{
		while (rows != NULL)
		{
			current = rows;
			rows = rows->next;
			free(current->line);
			free(current);
			current = NULL;
		}
		free(rows);
		rows = NULL;
	}
}

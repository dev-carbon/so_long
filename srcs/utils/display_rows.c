/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:01:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:02:15 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	display_rows(t_rows *rows)
{
	t_rows	*buff;

	buff = rows;
	while (buff != NULL)
	{
		printf("line => %s\n", buff->line);
		buff = buff->next;
	}
}

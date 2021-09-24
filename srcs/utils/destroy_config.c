/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:59 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 16:20:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	destroy_collectibles(t_collectible *collectible)
{
	t_collectible	*current;

	if (collectible != NULL)
	{
		while (collectible != NULL)
		{
			current = collectible;
			collectible = collectible->next;
			free(current);
			current = NULL;
		}
		free(collectible);
		collectible = NULL;
	}
}

static void	destroy_exits(t_exit *exit)
{
	t_exit	*current;

	if (exit != NULL)
	{
		while (exit != NULL)
		{
			current = exit;
			exit = exit->next;
			free(current);
			current = NULL;
		}
		free(exit);
		exit = NULL;
	}
}

void	destroy_config(t_config *config)
{
	if (config != NULL)
	{
		destroy_collectibles(config->collectibles);
		destroy_exits(config->exits);
		free(config);
		config = NULL;
	}
}

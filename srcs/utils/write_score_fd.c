/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_score_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:16 by humanfou          #+#    #+#             */
/*   Updated: 2021/09/21 15:01:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	write_score_fd(int items, int moves, int fd)
{
	ft_putstr_fd("items items: ", fd);
	ft_putnbr_fd(items, fd);
	ft_putchar_fd('\n', fd);;
	ft_putstr_fd("Total move: ", fd);
	ft_putnbr_fd(moves, fd);
	ft_putchar_fd('\n', fd);
}

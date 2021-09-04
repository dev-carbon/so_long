/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:46:15 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/01 21:46:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charlen(wchar_t c)
{
	int len;

	if (c < 128)
		len = 1;
	else if (c < 2048)
		len = 2;
	else if (c < 65536)
		len = 3;
	else
		len = 4;
	return (len);
}

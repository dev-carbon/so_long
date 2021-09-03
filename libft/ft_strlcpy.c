/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:39:01 by humanfou          #+#    #+#             */
/*   Updated: 2020/01/11 16:15:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	pos;
	size_t	len;

	pos = -1;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (++pos < (size - 1) && src[pos])
		dst[pos] = src[pos];
	dst[pos] = 0;
	return (len);
}

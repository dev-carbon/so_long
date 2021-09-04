/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:48:10 by humanfou          #+#    #+#             */
/*   Updated: 2020/12/05 09:55:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strnew(size_t size)
{
	size_t			i;
	char			*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i <= size)
		str[i] = '\0';
	return (str);
}

static int		get_line_len(char *hold)
{
	int				i;

	i = 0;
	while (hold[i] != '\0' && hold[i] != '\n')
		i++;
	return (i);
}

static char		*get_line(char *line, char **hold)
{
	char			*tmp;

	if (*hold == NULL)
		line = strnew(0);
	else if (ft_strchr(*hold, '\n'))
	{
		if (!(line = ft_substr(*hold, 0, get_line_len(*hold))))
			return (NULL);
		tmp = *hold;
		if (!(*hold = ft_substr(tmp, get_line_len(tmp) + 1, ft_strlen(tmp))))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(line = ft_strdup(*hold)))
			return (NULL);
		free(*hold);
		*hold = NULL;
	}
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static char		*hold = NULL;
	char			data[BUFFER_SIZE + 1];
	int				rb;
	char			*tmp;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rb = 0;
	while (!(ft_strchr(hold, '\n')) && (rb = read(fd, data, BUFFER_SIZE)) > 0)
	{
		data[rb] = '\0';
		tmp = hold;
		hold = (tmp) ? ft_strjoin(tmp, data) : ft_strdup(data);
		free(tmp);
	}
	if ((rb == -1) || (!(*line = get_line(*line, &hold))))
		return (-1);
	if (!(hold))
		return (0);
	return (1);
}

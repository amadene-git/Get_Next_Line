/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:17 by admadene          #+#    #+#             */
/*   Updated: 2019/10/30 14:19:39 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_current_line(int fd, char **save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret && !ft_chr(*save, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret)
		{
			buffer[ret] = 0;
			if (!(*save = ft_strjoin(*save, buffer)))
				return (-1);
		}
	}
	if (!*save)
		*save = ft_strdup("");
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[1024];
	char			*tmp;

	if (read(fd, NULL, 0) == -1 || !line)
		return (-1);
	if (!get_current_line(fd, &save[fd]))
		return (-1);
	tmp = save[fd];
	if (ft_chr(save[fd], '\n'))
	{
		if (!(*line = ft_sub(save[fd], 0, (ft_chr(save[fd], '\n') - save[fd]))))
			return (-1);
		save[fd] = ft_strdup(ft_chr(save[fd], '\n') + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(save[fd])))
			return (-1);
		*tmp = 0;
		return (0);
	}
	return (0);
}

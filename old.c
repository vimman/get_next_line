/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:39:51 by qdurot            #+#    #+#             */
/*   Updated: 2017/07/09 11:22:04 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	size_t				i;
	int					ret;
	char				rd[BUF_SIZE + 1];
	static char			*buf[OPEN_MAX];
	char				*ptr;

	i = 0;
	ptr = NULL;
	rd[BUF_SIZE] = '\0';
	if (fd > OPEN_MAX)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(0);
	ptr = ft_strchr(buf[fd], '\n');
	while (!ptr && (ret = read(fd, rd, BUF_SIZE)) > 0)
	{
		buf[fd] = ft_strjoin(buf[fd], rd);
		ptr = ft_strchr(buf[fd], '\n');
		free(buf[fd]);
	}
	if (ret < 0 || fd < 0)
		return (-1);
	if (!ptr && *buf[fd])
	{
		free(*line);
		*line = ft_strdup(buf[fd]);
		free(buf[fd]);
		buf[fd] = NULL;
		return(0);
	}
	else
	{
		*ptr = '\0';
		*line = ft_strsub(buf[fd], 0, (ptr - buf[fd]));
		buf[fd] = ft_strdup(ptr + 1);
		return (1);
	}
}
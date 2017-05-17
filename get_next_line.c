/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:39:51 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/17 19:35:02 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	size_t				i;
	size_t				k;
	int					ret;
	char				*read;
	char				*buf;
	char				*t_line;

	i = 0;
	k = 0;
	buf = '\0'
	while ((ret = read(fd, read, BUF_SIZE)))
	{
		read[BUF_SIZE] = '\0';
		buf = ft_strjoin(buf, read);
		if (sub = ft_strchr(buf, 0))
			buf = ft_strsub(buf, 0, ft_strlen(buf));
	}
	*line = buf;
	return (i);
}

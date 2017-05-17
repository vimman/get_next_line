/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:39:51 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/17 22:08:12 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	size_t				i;
	int					ret;
	char				*rd;
	char				*buf;

	i = 0;
	if (!(rd = ft_strnew(BUF_SIZE)))
		return (-1);
	buf = ft_strnew(0);
	while ((ret = read(fd, rd, BUF_SIZE)))
	{
		buf = ft_strjoin(buf, rd);
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strdup(buf);
			buf = ft_strsub(buf, 0, ft_strlen(buf));
		}
	}
	*line = buf;
	return (ret);
}

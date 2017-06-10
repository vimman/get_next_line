/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:39:51 by qdurot            #+#    #+#             */
/*   Updated: 2017/06/08 18:44:17 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	size_t				i;
	int					ret;
	char				rd[BUF_SIZE + 1];
	static char			*buf;
	char				*ptr;

	i = 0;
	ptr = NULL;

	rd[BUF_SIZE] = '\0';
	buf = ft_strnew(0);
	while (!(ptr) && (ret = read(fd, rd, BUF_SIZE)))
	{
		buf = ft_strjoin(buf, rd);
		ptr = ft_strchr(buf, '\n');
	}
	if (ptr)
	{
		*line = ft_strsub(buf, 0, *ptr);
		ret = 1;
	}
	else
	{
		*line = ft_strdup(buf);
		ft_strclr(buf);
		ret = 1;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:53:09 by qdurot            #+#    #+#             */
/*   Updated: 2017/07/09 10:55:24 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_SIZE 1
# define FD_MAX 10240

int				get_next_line(const int fd, char **line);


typedef struct	s_node	t_node;
struct			s_node
{
	int			fd;
	char		*buf;
	t_node		*next;
};

#endif

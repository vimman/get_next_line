/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:14:00 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/17 19:35:45 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (argc == 1)
	{
		fd = 0;
		get_next_line(fd, &tmp);
		ft_putstr(tmp);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &tmp))
		{
			ft_putstr(tmp);
		}
	}
	//else if (argc != 2)
	//	ft_putstr("fuck you man !");
	//fd = open(argv[1], O_RDONLY);
	//if (fd == -1)
	//	ft_putstr("open() failed \n");
	//while (get_next_line(fd, &tmp))
	//{
	//	printf("%s", tmp);
	//}
}

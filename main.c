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
	int		ret;
	int		fd[100];
	char	*tmp;

	i = 0;
	ret = 0;
	tmp = NULL;
	if (argc == 1)
	{
		while (!(ft_strcmp(tmp, "exit")))
		{
			get_next_line(fd[0], &tmp);
			ft_putendl(tmp);
		}
	}
	else if (argc == 2)
	{
		if ((fd[0] = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("open() failed \n");
		while ((ret = get_next_line(fd[0], &tmp)))
		{
			ft_putstr(tmp);
			ft_putstr("\n");
			//ft_putnbr(ret);
			//ft_putstr("\n");
		}
		//ret = get_next_line(fd[0], &tmp);
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr("for the moment we are using only one argument\n");
		return (0);
	}
	else 
		ft_putstr("fuck you man !");
}

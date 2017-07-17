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
		char		*line;
		int			fd;
		int			ret;
		int			count_lines;
		char		*filename;
		int			errors;

		filename = "gnl5_1.txt";
		fd = open(filename, O_RDONLY);
		if (fd > 2)
		{
			count_lines = 0;
			errors = 0;
			line = NULL;
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				if (count_lines == 0 && strcmp(line, "123") != 0)
					errors++;
				count_lines++;
				if (count_lines > 50)
					break ;
			}
			close(fd);
			if (count_lines != 1)
				printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
			if (errors > 0)
				printf("-> must have read \"123\" instead of \"%s\"\n", line);
			if (count_lines == 1 && errors == 0)
				printf("OK\n");
		}
		else
			printf("An error occured while opening file %s", filename);
		return (0);
	}
	else 
		ft_putstr("fuck you man !");
}

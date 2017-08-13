#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

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
		while (1)
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
			ft_putendl(tmp);
			ft_strdel(&tmp);
			//ft_putnbr(ret);
			//ft_putstr("\n");
		}
		//ft_putnbr(ret);
		//ft_putstr("\n");
	}
	else if (argc == 4)
	{
		int		fd1;
		int		fd2;
		int		fd3;
		char	*str1;
		char	*str2;
		char	*str3;

		fd1 = 0;
		fd2 = 0;
		fd3 = 0;
		if ((fd[0] = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("open() argv[1] failed \n");
		if ((fd[1] = open(argv[2], O_RDONLY)) == -1)
			ft_putstr("open() argv[2] failed \n");
		if ((fd[2] = open(argv[3], O_RDONLY)) == -1)
			ft_putstr("open() argv[3] failed \n");
		while ((fd1 = get_next_line(fd[0], &str1)) &&
				(fd2 = get_next_line(fd[1], &str2)) &&
				(fd3 = get_next_line(fd[2], &str3)))
		{
			ft_putendl(str1);
			ft_putendl(str2);
			ft_putendl(str3);
		}
		while ((fd1 = get_next_line(fd[0], &str1)))
			ft_putendl(str1);
		while ((fd2 = get_next_line(fd[1], &str2)))
			ft_putendl(str2);
		while ((fd3 = get_next_line(fd[2], &str3)))
			ft_putendl(str3);
	}
	else
	{
		ft_putstr("fuck you man !");
	}
	return (0);
}

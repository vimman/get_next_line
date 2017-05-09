#include "libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static size_t		i;
	size_t				k;
	int					ret;
	char				*buf;
	char				*t_line;

	i = 0;
	k = 0;
	if ((buf = (char *)malloc(sizeof(char) * BUF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[BUF_SIZE] = '\0';
		if (!(t_line = (char *)malloc(sizeof(char) * (ret + 1))))
			return (0);
		while (k < BUF_SIZE)
		{
			t_line[i] = buf[k];
			i++;
			k++;
		}
		k = 0;
	}
	*line = t_line;
	return (i);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	tmp = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	if (argc != 2)
		ft_putstr("fuck you man !");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed \n");
	while (get_next_line(fd, &tmp))
	{
		printf("%s", tmp);
	}
}

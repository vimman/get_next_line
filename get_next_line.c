#include "libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	size_t	i;
	static int		ret;
	char	*buf;
	char	*line;

	if (buf = (char *)malloc(sizeof(char) * BUF_SIZE))
		return (-1);
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
	}

}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	if (argc != 2)
		ft_putstr("fuck you man !");
	fd = open(argv[1], O_READONLY);
	if (fd == -1)
		ft_putstr("open() failed \n");
	while (get_next_line(fd, *tmp))
	{
		printf("%s", tmp);
	}
}

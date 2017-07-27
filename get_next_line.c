#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

int		ft_find_n(char *buf, int fd, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUFF_SIZE + 1];

	if (!buf)
		buf = ft_strdup(0);
	rd[BUFF_SIZE] = '\0';
	ptr = ft_strchr(buf, '\n');
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		rd[ret] = '\0';
		buf = ft_strjoin(buf, rd);
		ptr = ft_strchr(buf, '\n');
	}
	if (!ptr && buf)
	{
		*line = ft_strdup(buf);
		buf = NULL;
		return (0);
	}
	else
	{
		*ptr = '\0';
		*line = ft_strdup(buf);
		buf = ft_strdup(ptr + 1);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*buf[FD_MAX];

	if (fd > FD_MAX || fd < 0 || line == NULL)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(0);
	ret = (ft_find_n(buf[fd], fd, line));
	return (ret);
}

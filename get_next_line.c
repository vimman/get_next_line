#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

/** 
 * fill_line
 **/
int		get_next_line(const int fd, char **line)
{
	size_t				i;
	int					ret;
	char				rd[BUFF_SIZE + 1];
	static char			*buf[FD_MAX];
	char				*ptr;

	i = 0;
	ptr = NULL;
	rd[BUFF_SIZE] = '\0';
	if (fd > FD_MAX)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(0);
	ptr = ft_strchr(buf[fd], '\n');
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		buf[fd] = ft_strjoin(buf[fd], rd);
		ptr = ft_strchr(buf[fd], '\n');
	}
	if (ret < 0 || fd < 0)
		return (-1);
	if (!ptr && *buf[fd])
	{
		*line = ft_strdup(buf[fd]);
		buf[fd] = NULL;
		return(1);
	}
	else if (!buf[fd] || !*buf[fd])
		return(0);
	else
	{
		*ptr = '\0';
		*line = ft_strsub(buf[fd], 0, (ptr - buf[fd]));
		buf[fd] = ft_strdup(ptr + 1);
		return (1);
	}
}

#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

char	*ft_freejoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	free(s1);
	i = -1;
	while (s2[++i])
		ret[len_s1 + i] = s2[i];
	ret[len_s1 + len_s2] = '\0';
	return (ret);
}

int		ft_split(char **buf, char **line, char *ptr)
{
	if (ptr == '\0' && **buf)
	{
		*line = ft_freejoin(*buf, "");
		return (1);
	}
	else if (ptr && **buf)
	{
		*ptr = '\0';
		*line = ft_freejoin(*buf, "");
		*buf = ft_strdup(ptr + 1);
		return (1);
	}
	else
		return (0);
}

int		ft_find_n(int fd, char **line)
{
	int			ret;
	char		*ptr;
	static char	*buf[FD_MAX];
	char		rd[BUFF_SIZE + 1];

	if (!buf[fd])
		buf[fd] = ft_strnew(0);
	ptr = ft_strchr(buf[fd], '\n');
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		rd[ret] = '\0';
		buf[fd] = ft_freejoin(buf[fd], rd);
		ptr = ft_strchr(buf[fd], '\n');
	}
	return (ft_split(&buf[fd], line, ptr));
}

int		get_next_line(const int fd, char **line)
{
	char	*buf;

	buf = NULL;
	if (fd > FD_MAX || fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	return (ft_find_n(fd, line));
}

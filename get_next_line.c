#include <stdio.h> //Attention
#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

char	*ft_freejoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	free(s1);
	i = 0;
	while (s2[i])
	{
		ret[len_s1 + i] = s2[i];
		i++;
	}
	ret[len_s1 + len_s2] = '\0';
	return (ret);
}

int		ft_find_n(char *buff, int fd, char **line)
{
	int		ret;
	char	*ptr;
	static char	*buf[FD_MAX];
	char	rd[BUFF_SIZE + 1];

	if (!buf[fd])
		buf[fd] = buff;
	ptr = ft_strchr(buf[fd], '\n');
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		buf[fd] = ft_freejoin(buf[fd], rd);
		ptr = ft_strchr(buf[fd], '\n');
		ft_strclr(rd);
	}
	if (ptr == '\0' && buf[fd])
	{
		*line = ft_strdup(buf[fd]);
		return (0);
	}
	else
	{
		*ptr = '\0';
		*line = ft_strdup(buf[fd]);
		buf[fd] = ft_strdup(ptr + 1);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char	*buf;

	buf = NULL;
	if (fd > FD_MAX || fd < 0 || line == NULL)
		return (-1);
	if (!buf)
		buf = ft_strnew(0);
	return (ft_find_n(buf, fd, line));
}


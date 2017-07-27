int		ft_read(int fd, t_list buf, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUFF_SIZE + 1];

	(void)line;
	rd[BUFF_SIZE] = '\0';
	ptr = NULL;
	ptr = ft_strchr(buf.content, '\n');
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		buf.content= ft_strjoin(buf.content, rd);
		ptr = ft_strchr(buf.content, '\n');
	}
	if (!ptr && buf.content)
	{
		free(*line);
		*line = ft_strdup(buf.content);
		free(buf.content);
		buf.content= NULL;
		return(0);
	}
	else
	{
		*ptr = '\0';
		*line = ft_strsub(buf.content, 0, (ptr - (char *)buf.content));
		if (ptr + 1)
			buf.content = ft_strdup(ptr + 1);
		else
			free(buf.content);
		return (1);
	}

}

int		get_next_line(const int fd, char **line)
{
	static t_list		buf[FD_MAX];
	int					ret;

	if (fd > FD_MAX)
		return (-1);
	if (!(buf[fd].content))
	{
		buf[fd] = *ft_lstnew(NULL, 0);
		buf[fd].content = ft_strnew(0);
	}
	ret = ft_read(fd, buf[fd], line);
	if (fd < 0 || ret < 0)
		return (-1);
	return (ret);
}

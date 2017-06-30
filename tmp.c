int		get_next_line(const int fd, char **line)
{
	size_t				i;
	int					ret;
	char				*rd;
	static char			*buf;
	char				*ptr;

	i = 0;
	ptr = NULL;

	if (!(rd = (char *)malloc(sizeof(char) * BUF_SIZE)))
		return (-1);
	rd[BUF_SIZE] = '\0';
	buf = ft_strnew(0);
	while (!ptr &&(ret = read(fd, rd, BUF_SIZE)))
	{
		buf = ft_strjoin(buf, rd);
		ptr = ft_strchr(buf, '\n');
	}
	if (ptr)
	{
		*line = ft_strsub(buf, 0, *ptr);
		ret = 1;
	}
	else
	{
		*line = ft_strdup(buf);
		ft_strclr(buf);
		ret = 1;
	}
	return (ret);
}

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

int		ft_read(int fd, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUF_SIZE + 1];
	t_list	*lst;
	t_box	*box;

	ft_bzero(rd, (BUF_SIZE + 1));
	while (!ptr && (ret = read(fd, rd, BUF_SIZE)) > 0)
	{
		lst = ft_lstnew(&box, sizeof(t_box));
		lst->content->buf = rd;
		lst->content->fd = fd;
		ptr = ft_memchr(lst->content->buf, '\n');
	}
}

int		get_next_line(int fd, char **line)
{
	if (fd > FD_MAX)
		return (1);
}

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

int		ft_read(int fd, **line)
{
	char	rd[BUF_SIZE + 1];
	t_list	lst;

	ft_bzero(rd, (BUF_SIZE + 1));
	while (!ptr && (ret = read(fd, rd, BUF_SIZE)) > 0)
	{
		lst = ft_lstnew(box, sizeof(t_box));
		lst->box->buf = rd;
		lst->box->fd = fd;
		ptr = ft_memchr(lst->content->buf, 0);
	}
}

int		get_next_line(int fd, **line)
{
	if (fd > FD_MAX)
		return (1);
}

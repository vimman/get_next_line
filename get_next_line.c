#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"


char			*ft_freejoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	i = -1;
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

static t_list	*ft_node(t_list **list, int fd)
{
	t_list	*node;
	char	*buf;

	node = *list;
	/* Search for the file descriptor in the list*/
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	/* If any node have been found with this file descriptor
	 * add a new one to the list */
	buf = "\0";
	if (!(node = ft_lstnew(buf, 1)))
		return (NULL);
	node->content_size = fd;
	ft_lstadd(list, node);
	return (node);
}

int		ft_read(char **buf, int fd, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUFF_SIZE + 1];

	/* Look for a '\n' in the buffer */

	ptr = ft_strchr(*buf, '\n');
	ft_bzero(rd, BUFF_SIZE);

	/* Read and join buf until it finds a '\n' or read return 0 */

	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		if (!(*buf= ft_freejoin(*buf, rd)))
			return (-1);
		if ((ptr = ft_strchr(*buf, '\n')))
			break;
	}

	/* If '\n' is found replace it by a '\0' and copy the line in 'line'*/

	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strdup(*buf);
		*buf = ft_strdup(ptr + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(*buf);
		*buf = ft_strdup("\0");
		return ((*rd || **line) ?  1 : 0);
	}
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*list;
	t_list			*node;

	/* Create or retrieve file node*/
	if (!(node = ft_node(&list, fd)))
		return (-1);
	/* Verifie if fd is ok, if line exist and if file is openned */
	if (fd > FD_MAX || fd < 0 || line == NULL ||
			read(fd, node->content, 0) < 0)
		return (-1);
	ret = ft_read((char **)&node->content, fd, line);
	return (ret);
}

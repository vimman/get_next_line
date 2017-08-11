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

static t_node	*ft_node(int fd)
{
	static t_node	*node;
	t_node			*new;
	t_node			*tmp;
	
	/* If the list doesn't exist, create it */
	if (!node)
	{
		if (!(node = (t_node *)malloc(sizeof(t_node))))
			return (NULL);
		node->fd = fd;
		node->buf = ft_strnew(0);
		node->next = NULL;
		return (node);
	}
	/* Search for the file descriptor in the list*/
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	/* If any node have been found with this file descriptor
	 * add a new one to the list */
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	tmp = node;
	new->next = tmp;
	new->buf = ft_strnew(0);
	new->fd = fd;
	node = new;
	return (node);
}

int		ft_read(char *buf, int fd, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUFF_SIZE + 1];

	/* Look for a '\n' in the buffer */
	ptr = ft_strchr(buf, '\n');
	ft_bzero(rd, BUFF_SIZE);
	/* Read and join buf until it finds a '\n' or read return 0 */
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		rd[ret] = '\0';
		buf = ft_freejoin(buf, rd);
		ptr = ft_strchr(buf, '\n');
	}
	if (!ptr && buf)
	{
		*line = ft_strdup(buf);
		return (ret ? 1 : 0);
	}
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strdup(buf);
		buf = ft_strdup(ptr + 1);
		return (1);
	}
	else 
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	t_node	*node;

	node = ft_node(fd);
	if (fd > FD_MAX || fd < 0 || line == NULL || read(fd, node->buf, 0) < 0)
		return (-1);
	ret = ft_read(node->buf, fd, line);
	return (ret);
}

#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

/*
** Join two string and free the first one
*/

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

/*
** Search for the file descriptor in the list
** Create it if doesn't exist
** Add a new node if fd haven't been found in the list
*/

static t_list	*ft_node(t_list **list, int fd)
{
	t_list	*node;
	char	*buf;

	node = *list;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	buf = "\0";
	if (!(node = ft_lstnew(buf, 1)))
		return (NULL);
	node->content_size = fd;
	ft_lstadd(list, node);
	return (node);
}

/*
** Read and join buf until it finds a '\n' or read return 0
*/

char			*ft_read(char **buf, int fd, char *ptr)
{
	int		ret;
	char	rd[BUFF_SIZE + 1];

	while ((ret = read(fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		if (!(*buf = ft_freejoin(*buf, rd)))
			return (NULL);
		if ((ptr = ft_strchr(*buf, '\n')))
			return (ptr);
	}
	return (0);
}

/*
** This function verify if conditions are ok, set the pointer to '\n'
** call ft_read or split the buffer if necessary
*/

int				get_next_line(const int fd, char **line)
{
	char			*ptr;
	static t_list	*list;
	t_list			*node;

	if (!(node = ft_node(&list, fd)) || fd > FD_MAX || fd < 0 ||
			line == NULL || read(fd, node->content, 0) < 0)
		return (-1);
	ptr = ft_strchr(node->content, '\n');
	if (!ptr)
		ptr = ft_read((char **)&node->content, fd, ptr);
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_freejoin((char *)node->content, "");
		node->content = ft_strdup(ptr + 1);
		return (1);
	}
	*line = ft_strdup(node->content);
	node->content = ft_strdup("\0");
	return ((**line) ? 1 : 0);
}

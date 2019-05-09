#include "libft.h"

static t_gnl	*get_file(const int fd, t_list **alst)
{
	t_list		*elem;
	t_gnl		file;

	elem = *alst;
	while (elem)
	{
		if (((t_gnl *)(elem->content))->fd == fd)
			return (elem->content);
		elem = elem->next;
	}
	file.fd = fd;
	if (!(file.data = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(elem = ft_lstnew(&file, sizeof(t_gnl))))
		return (NULL);
	ft_lstadd(alst, elem);
	return ((*alst)->content);
}

static int			read_line(t_gnl *file)
{
	int			nb_bytes;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	nb_bytes = 1;
	while (nb_bytes > 0 && !ft_strchr(file->data, '\n'))
	{
		if (((nb_bytes = read(file->fd, &buff, BUFF_SIZE)) < 0)
			|| BUFF_SIZE < 1)
			return (-1);
		buff[nb_bytes] = '\0';
		tmp = file->data;
		file->data = ft_strjoin(file->data, buff);
		free(tmp);
		ft_memset(buff, 0, nb_bytes);
	}
	return (nb_bytes);
}

static char			*update_line(char *str)
{
	char	*pos;

	if (!(pos = ft_strchr(str, '\n')))
		return (ft_strdup(str));
	else
		return (ft_strsub(str, 0, pos - str));
}

static void			shift_line(char **data)
{
	char *tmp;
	char *pos;

	tmp = *data;
	if (!(pos = ft_strchr(tmp, '\n')))
		*data = ft_strnew(0);
	else
		*data = ft_strdup(pos + 1);
	free(tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*file;
	char			*tmp;
	int				nb_bytes;

	if (!line || fd < 0)
		return (-1);
	file = get_file(fd, &lst);
	if ((nb_bytes = read_line(file)) == -1)
		return (-1);
	*line = update_line(file->data);
	shift_line(&(file->data));
	tmp = file->data;
	if (!**line && !nb_bytes)
		return (0);
	else
		return (1);
}
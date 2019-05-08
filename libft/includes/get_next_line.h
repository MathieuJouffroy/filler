#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# define BUFF_SIZE 32

typedef struct				s_gnl
{
	int						fd;
	char					*data;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
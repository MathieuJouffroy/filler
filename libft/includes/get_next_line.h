/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:27:07 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 18:45:57 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# define BUFF_SIZE 1

typedef struct				s_gnl
{
	int						fd;
	char					*data;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif

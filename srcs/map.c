/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:23 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 19:01:21 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_map_data(t_filler *filler)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (gnl_exit(line));
	if (ft_strcmp(filler->data, line))
		return (gnl_exit(line));
	ft_memdel((void**)&line);
	filler->pnt.min = filler->size;
	return (1);
}

int			check_map_first_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp[i] != '\0')
	{
		if (i < 4 && tmp[i] != ' ')
			return (0);
		if (i > 4 && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			chek_map_line_nb(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp[i] != '\0')
	{
		if (i < 3 && !(ft_isdigit(tmp[i])))
			return (0);
		if (i == 3 && tmp[i] != ' ')
			return (0);
		if (i > 3 && tmp[i] != '.' && tmp[i] != 'O' && tmp[i] != 'X')
			return (0);
		i++;
	}
	return (1);
}

int			fill_map(t_filler *filler)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (gnl_exit(line));
	if (!check_map_first_line(line))
		return (gnl_exit(line));
	ft_memdel((void**)&line);
	while (i < filler->map.height)
	{
		if (get_next_line(0, &line) <= 0)
			return (gnl_exit(line));
		if (!chek_map_line_nb(line))
			return (gnl_exit(line));
		ft_strncpy(filler->map.board[i], (line + 4), filler->map.width + 1);
		ft_memdel((void**)&line);
		i++;
	}
	return (1);
}

int			parse_map(t_filler *filler)
{
	if (filler->init_m == 1)
	{
		if (!check_map_data(filler))
			return (errors(filler, 7));
	}
	if (!fill_map(filler))
		return (errors(filler, 3));
	filler->init_m = 1;
	return (1);
}

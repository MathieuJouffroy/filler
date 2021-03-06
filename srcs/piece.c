/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:29 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 19:07:41 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			valid_line(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		if (line[i] == '*')
			filler->piece.p_cnt++;
		i++;
	}
	if (i != filler->piece.width)
		return (0);
	return (1);
}

int			fill_piece(t_filler *filler)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (i < filler->piece.height)
	{
		if (get_next_line(0, &line) <= 0)
			return (gnl_exit(line));
		if (!valid_line(filler, line))
			return (gnl_exit(line));
		ft_strcpy(filler->piece.square[i], line);
		ft_memdel((void**)&line);
		i++;
	}
	return (1);
}

void		get_point_pos(t_filler *filler)
{
	int		i;
	int		j;
	int		p_cnt;

	i = 0;
	p_cnt = 0;
	while (i < filler->piece.height)
	{
		j = 0;
		while (filler->piece.square[i][j])
		{
			if (filler->piece.square[i][j] == '*')
			{
				filler->piece.p[p_cnt].x = j;
				filler->piece.p[p_cnt].y = i;
				filler->piece.p[p_cnt].min = filler->pnt.min;
				p_cnt++;
			}
			j++;
		}
		i++;
	}
}

int			parse_piece(t_filler *filler)
{
	if (!get_piece_size(filler))
		return (errors(filler, 4));
	if (!init_piece(filler))
		(errors(filler, 5));
	if (!fill_piece(filler))
		return (errors(filler, 6));
	if (!(filler->piece.p = (t_point*)ft_memalloc(sizeof(t_point)
		* filler->piece.p_cnt)))
		return (errors(filler, 5));
	get_point_pos(filler);
	return (1);
}

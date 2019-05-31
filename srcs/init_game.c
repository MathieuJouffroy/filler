/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:18 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 19:22:07 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_player_id(t_filler *filler, int ret)
{
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (gnl_exit(line));
	if ((ft_strncmp(line, "$$$ exec p", 10)) && (line[12] != ':'))
		ret = 0;
	if (line[14] == '[')
		while (line[14 + i])
			i++;
	else
		ret = 0;
	if (line[12] != ':' || line[13 + i] != ']')
		ret = 0;
	if (line[10] == '1' || line[10] == '2')
	{
		filler->me = (line[10] == '1') ? 'O' : 'X';
		filler->bot = (line[10] == '1') ? 'X' : 'O';
	}
	else
		ret = 0;
	ft_memdel((void**)&line);
	return (ret);
}

int				get_map_size(t_filler *filler)
{
	char		*line;
	int			ret;
	int			i;

	line = NULL;
	ret = 1;
	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (gnl_exit(line));
	filler->data = ft_strdup(line);
	if (ft_strncmp(line, "Plateau ", 8)
			|| !(filler->map.height = ft_atoi(line + 8)))
		ret = 0;
	i = ft_digitcount(filler->map.height) + 1;
	if (!(filler->map.width = ft_atoi(line + 8 + i)))
		ret = 0;
	i += ft_digitcount(filler->map.width);
	if (line[8 + i] != ':')
		ret = 0;
	ft_memdel((void**)&line);
	return (ret);
}

int				get_piece_size(t_filler *filler)
{
	char		*line;
	int			ret;
	int			i;

	line = NULL;
	ret = 1;
	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (gnl_exit(line));
	if (ft_strncmp(line, "Piece ", 6)
			|| (!(filler->piece.height = ft_atoi(line + 6))))
		ret = 0;
	i = ft_digitcount(filler->piece.height) + 1;
	if (!(filler->piece.width = ft_atoi(line + 6 + i)))
		ret = 0;
	i += ft_digitcount(filler->piece.width);
	if (line[6 + i] != ':')
		ret = 0;
	ft_memdel((void**)&line);
	return (ret);
}

int				init_map(t_filler *filler)
{
	int			i;

	if (!(filler->map.board = (char**)ft_memalloc(sizeof(char*)
					* filler->map.height)))
		return (0);
	i = 0;
	while (i < filler->map.height)
	{
		if (!(filler->map.board[i] = (char*)ft_memalloc(sizeof(char)
						* filler->map.width + 1)))
			return (0);
		i++;
	}
	return (1);
}

int				init_piece(t_filler *filler)
{
	int i;

	if (!(filler->piece.square = (char**)ft_memalloc(sizeof(char*)
					* filler->piece.height)))
		return (0);
	i = 0;
	while (i < filler->piece.height)
	{
		if (!(filler->piece.square[i] = (char*)ft_memalloc(sizeof(char)
						* filler->piece.width + 1)))
			return (0);
		i++;
	}
	return (1);
}

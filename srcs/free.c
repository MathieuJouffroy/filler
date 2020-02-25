/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:09 by mjouffro          #+#    #+#             */
/*   Updated: 2019/06/04 20:26:58 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (piece->square != NULL)
	{
		while (i < piece->height)
			free(piece->square[i++]);
		free(piece->square);
	}
	if (piece->p)
		free(piece->p);
	piece->p = NULL;
	piece->square = NULL;
	piece->p_cnt = 0;
	piece->width = 0;
	piece->height = 0;
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (map->board != NULL)
	{
		while (i < map->height)
		{
			ft_strdel(&map->board[i]);
			i++;
		}
		free(map->board);
	}
	map->board = NULL;
	map->width = 0;
	map->height = 0;
	map->size = 0;
}

void	free_struct(t_filler *filler)
{
	free_map(&filler->map);
	if (filler->piece.height)
		free_piece(&filler->piece);
	if (filler->data)
		free(filler->data);
	filler->data = NULL;
}

int		gnl_exit(char *line)
{
	ft_memdel((void**)&line);
	return (0);
}

int		errors(t_filler *filler, int i)
{
	if (i == 0)
		ft_dprintf(2, "usage : $$$ exec pPLAYER_NUMBER : [PLAYER_NAME]\n");
	if (i == 1)
		ft_dprintf(2, "usage : Plateau MAP_ROW MAP_COL:\n");
	if (i == 2)
		ft_dprintf(2, "Plateau : Memory Allocation Error\n");
	if (i == 3)
		ft_dprintf(2, "Plateau Format Error.\n");
	if (i == 4)
		ft_dprintf(2, "usage : Piece PIECE_ROW PIECE_COL:\n");
	if (i == 5)
		ft_dprintf(2, "Piece : Memory Allocation Error.\n");
	if (i == 6)
		ft_dprintf(2, "Piece Format Error.\n");
	if (i == 7)
		ft_dprintf(2, "usage : Plateau size can't change during game.\n");
	if (i == 8)
		ft_dprintf(2, "Plateau : line Format Error.\n");
	free_struct(filler);
	return (0);
}

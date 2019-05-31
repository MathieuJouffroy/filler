/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:13 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 19:28:06 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			play(t_filler *filler)
{
	t_point	ref;
	int		end;

	ref.y = 0;
	end = 0;
	while (ref.y < filler->map.height)
	{
		ref.x = 0;
		while (ref.x < filler->map.width)
		{
			if ((filler->map.board[ref.y][ref.x] == filler->me)
				|| (filler->map.board[ref.y][ref.x] == ft_tolower(filler->me)))
			{
				if (check_around_ref(filler, &ref))
				{
					if (check_piece_pnts(filler, &ref))
						end = get_min_dist(filler, &ref) ? 1 : 0;
				}
			}
			ref.x++;
		}
		ref.y++;
	}
	return (game_end(filler, end));
}

int			game_end(t_filler *filler, int end)
{
	if (end == 1)
	{
		print_piece_pos(filler);
		free_piece(&filler->piece);
		filler->pnt.x = 0;
		filler->pnt.y = 0;
		filler->pnt.good = 0;
		filler->pnt.min = filler->size;
	}
	else
	{
		free_struct(filler);
		ft_putstr("0 0\n");
	}
	return (end);
}

void		print_piece_pos(t_filler *filler)
{
	int		i;
	int		cnt;
	int		x;
	int		y;

	i = 0;
	cnt = 0;
	while (i < filler->piece.p_cnt)
	{
		filler->piece.p[i].i = i;
		if (is_pnt_placeable(filler, &filler->piece.p[i], &filler->pnt))
		{
			if (filler->piece.p[i].min <= filler->pnt.min)
				cnt = i;
		}
		i++;
	}
	x = filler->pnt.x - filler->piece.p[cnt].x;
	y = filler->pnt.y - filler->piece.p[cnt].y;
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

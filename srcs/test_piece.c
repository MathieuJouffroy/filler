/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:03:39 by mjouffro          #+#    #+#             */
/*   Updated: 2019/04/26 15:54:02 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_pnt_placeable(t_filler *filler, t_point *to_test, t_point *ref)
{
	int i;
	int	x;
	int	y;

	i = 0;
	while (i < filler->piece.p_cnt)
	{
		y = (filler->piece.p[i].y - to_test->y + ref->y);
		x = (filler->piece.p[i].x - to_test->x + ref->x);
		if (!(i == to_test->i))
		{
			if (!check_overflow(filler, x, y))
				return (0);
			if (filler->map.board[y][x] != '.')
				return (0);
			i++;
		}
		else
			i++;
	}
	return (1);
}

int		check_piece_pnts(t_filler *filler, t_point *ref)
{
	t_point test;
	int i;

	test.i = 0;
	while (test.i < filler->piece.p_cnt)
	{
		test.x = filler->piece.p[test.i].x;
		test.y = filler->piece.p[test.i].y;
		filler->piece.p[test.i].good = is_pnt_placeable(filler, &test, ref);
		test.i++;
	}
	i = 0;
	while (i < filler->piece.p_cnt)
	{
		if (filler->piece.p[i].good)
			return (1);
		i++;
	}
	return (0);
}

int	check_overflow(t_filler *filler, int x, int y)
{
	if ((y < 0) || (x < 0))
		return (0);
	if ((y >= filler->map.height) || (x >= filler->map.width))
		return (0);
	return (1);
}

int		check_around_ref(t_filler *filler, t_point *ref)
{
	if ((ref->x + 1 < filler->map.width)
		&& filler->map.board[ref->y][ref->x + 1] == '.')
		return (1);
	if ((ref->x - 1 > 0) && filler->map.board[ref->y][ref->x - 1] == '.')
		return (1);
	if ((ref->y - 1 > 0) && filler->map.board[ref->y - 1][ref->x] == '.')
		return (1);
	if ((ref->y + 1 < filler->map.height)
		&& filler->map.board[ref->y + 1][ref->x] == '.')
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:30:05 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 19:40:17 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <math.h>

/*
** diagonal = √(w^2 + h^2) = sqrt(power2(w) + power2(h))
** w = bot->x - new_pnt_x
** h = bot->y - new_pnt_y
** new_pnt_x / new_pnt_y = (coord of the pnt of new piece on which
** 						I am) - (coord of the pnt of the new piece i am
** 						placing on a pnt of my board pieces) + (coord of
**						the map piece pnt i am placing the new piece on)
*/

double		min_dist(t_filler *filler, t_point *ref, t_point *test,
			t_point *bot)
{
	int		i;
	int		new_pnt_x;
	int		new_pnt_y;
	double	min;
	double	res;

	i = 0;
	min = filler->pnt.min;
	new_pnt_x = filler->piece.p[i].x - test->x + ref->x;
	new_pnt_y = filler->piece.p[i].y - test->y + ref->y;
	while (i < filler->piece.p_cnt)
	{
		if (!(i == test->i))
		{
			res = ft_pow((bot->x - new_pnt_x), 2);
			res += ft_pow((bot->y - new_pnt_y), 2);
			res = ft_sqrt(res);
			min = (res < min) ? res : min;
			i++;
		}
		else
			i++;
	}
	return (min);
}

double		piece_pnt_min_dist(t_filler *filler, t_point *ref, t_point *bot)
{
	t_point test;
	double	min;
	double	res;

	test.i = 0;
	min = filler->pnt.min;
	ft_bzero(&test, sizeof(test));
	while (test.i < filler->piece.p_cnt)
	{
		test.x = filler->piece.p[test.i].x;
		test.y = filler->piece.p[test.i].y;
		if (is_pnt_placeable(filler, &test, ref))
		{
			res = min_dist(filler, ref, &test, bot);
			if (res < filler->piece.p[test.i].min)
				filler->piece.p[test.i].min = res;
			min = (res < min) ? res : min;
		}
		test.i++;
	}
	return (min);
}

int			get_min_dist(t_filler *filler, t_point *ref)
{
	double	min;
	t_point	bot;

	min = filler->size;
	bot.y = -1;
	while (++bot.y < filler->map.height)
	{
		bot.x = 0;
		while (bot.x < filler->map.width)
		{
			if ((filler->map.board[bot.y][bot.x] == filler->bot)
			|| (filler->map.board[bot.y][bot.x] == ft_tolower(filler->bot)))
			{
				min = piece_pnt_min_dist(filler, ref, &bot);
				if (min < filler->pnt.min)
				{
					filler->pnt.x = ref->x;
					filler->pnt.y = ref->y;
					filler->pnt.min = min;
				}
			}
			bot.x++;
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:29:03 by mjouffro          #+#    #+#             */
/*   Updated: 2019/06/04 21:25:40 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_game(t_filler *filler)
{
	if (!(get_player_id(filler, 1)))
		return (errors(filler, 0));
	if (!get_map_size(filler))
		return (errors(filler, 1));
	if (!init_map(filler))
		return (errors(filler, 2));
	filler->size = filler->map.width * filler->map.height;
	filler->pnt.min = filler->size;
	return (1);
}

int			start_game(t_filler *filler)
{
	int		playing;

	playing = 1;
	while (playing)
	{
		if (!parse_map(filler))
			break ;
		if (!parse_piece(filler))
			break ;
		playing = play(filler);
	}
	return (1);
}

int			main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!init_game(&filler))
		return (0);
	start_game(&filler);
	return (0);
}

/*
** __attribute__((destructor)) int end (){
** while(1);
** };
*/

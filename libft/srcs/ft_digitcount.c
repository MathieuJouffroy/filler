/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:36:58 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/24 11:29:30 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_digitcount(int nb)
{
	size_t			count;

	count = 0;
	if (nb < 10 && nb > -10)
		return (1);
	while (nb)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

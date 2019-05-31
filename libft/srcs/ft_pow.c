/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:28:10 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/31 14:53:54 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int pow)
{
	double	tmp;

	if (pow == 0)
		return (1);
	tmp = ft_pow(nb, pow / 2);
	if ((pow % 2) == 0)
		return (tmp * tmp);
	else
	{
		if (pow > 0)
			return (nb * tmp * tmp);
		else
			return ((tmp * tmp) / nb);
	}
}

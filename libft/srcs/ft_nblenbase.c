/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblenbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:28:05 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/15 18:28:06 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblenbase(uintmax_t n, unsigned int base)
{
	return (n < base ? 1 : 1 + ft_nblenbase(n / base, base));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:44:25 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/22 19:20:26 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	if (src > dst)
		ft_memcpy(tmp, src, len);
	if (src < dst)
	{
		src = src + (len - 1);
		tmp = tmp + (len - 1);
		while (len--)
			*(tmp--) = *(unsigned char*)src--;
	}
	return (dst);
}

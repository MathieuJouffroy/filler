/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:48:32 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/24 13:41:18 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_ptr;

	dst_ptr = dst;
	while (n--)
	{
		if ((*(dst_ptr++) = *(unsigned char*)src++) == (unsigned char)c)
		{
			dst = dst_ptr;
			return (dst);
		}
	}
	return (NULL);
}

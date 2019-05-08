/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:27:43 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/27 12:26:45 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *src, size_t len, size_t newlen)
{
	void	*res;

	if (!src)
		return (NULL);
	if (len >= newlen)
		return (src);
	if (len == 0)
		return ((void*)ft_memalloc(newlen));
	res = (void*)malloc(newlen);
	res = ft_memcpy(res, src, len);
	free(src);
	return (res);
}

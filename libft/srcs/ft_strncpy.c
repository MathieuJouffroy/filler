/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:47:31 by mjouffro          #+#    #+#             */
/*   Updated: 2019/05/10 12:53:04 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(src);
	ft_bzero((void*)dst, len);
	ft_memcpy(dst, src, len > size ? size : len);
	return (dst);
}

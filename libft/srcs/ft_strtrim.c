/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:24:08 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/22 16:09:34 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start_i;
	size_t	end_i;
	size_t	len;

	start_i = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[start_i]))
		start_i++;
	if (!s[start_i])
		return (ft_strnew(1));
	end_i = (ft_strlen(s) - 1);
	while (ft_iswhitespace(s[end_i]))
		end_i--;
	len = end_i - start_i + 1;
	if (!(new = ft_strsub(s, start_i, len)))
		return (NULL);
	return (new);
}

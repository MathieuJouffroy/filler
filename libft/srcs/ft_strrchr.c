/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:33:58 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/22 16:06:26 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;
	int		last_i;

	last_i = ft_strlen(s);
	last_occurence = (char*)s + last_i;
	while (*last_occurence != c && last_i--)
		last_occurence--;
	return (*last_occurence == c ? last_occurence : NULL);
}

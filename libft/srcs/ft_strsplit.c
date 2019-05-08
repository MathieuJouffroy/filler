/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:48:11 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/27 14:05:39 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_newlen(char *s, char c)
{
	size_t n;

	while (*s != '\0' && *s == c)
		s++;
	n = (*s ? 1 : 0);
	while (*s != '\0')
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			n++;
		s++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	n;
	char	*tmp;
	char	**new_t;

	if (!s)
		return (NULL);
	n = ft_newlen((char*)s, c);
	if ((new_t = (char**)malloc(sizeof(char*) * (n + 1))) == NULL)
		return (NULL);
	tmp = (char*)s;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (tmp != s)
				*(new_t++) = ft_strsub(tmp, 0, s - tmp);
			tmp = (char*)s + 1;
		}
		s++;
	}
	if (tmp != s)
		*(new_t++) = ft_strsub(tmp, 0, s - tmp);
	*new_t = NULL;
	return (new_t - n);
}

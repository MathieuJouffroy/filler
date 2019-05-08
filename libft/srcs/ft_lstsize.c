/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:38:28 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/23 13:38:31 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list **alst)
{
	size_t	len;
	t_list	*lst;

	if (!alst)
		return (0);
	if (!(lst = *alst))
		return (0);
	len = 1;
	while (lst->next != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

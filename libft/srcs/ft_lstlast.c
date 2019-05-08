/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:37:48 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/23 13:52:43 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list **alst)
{
	t_list *tmp;

	if (!alst)
		return (NULL);
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

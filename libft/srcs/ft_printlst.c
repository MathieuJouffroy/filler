/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:40:17 by mjouffro          #+#    #+#             */
/*   Updated: 2018/11/23 13:41:08 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list **alst)
{
	t_list	*node;

	if (!alst)
		return ;
	node = *alst;
	while (node != NULL)
	{
		write(1, node->content, node->content_size);
		node = node->next;
	}
}

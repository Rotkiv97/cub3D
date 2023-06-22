/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:13:02 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/12 16:20:28 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*d;

	tmp = *lst;
	while (tmp)
	{
		d = tmp;
		tmp = tmp->next;
		(*del)(d->content);
		d->next = NULL;
		free(d);
	}
	*lst = NULL;
}

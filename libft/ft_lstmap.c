/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:29:22 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/15 18:41:04 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmpn;
	t_list	*new;

	new = 0;
	tmp = lst;
	if (tmp)
	{
		new = ft_lstnew((*f)(tmp->content));
		if (!new)
			ft_lstclear(&new, (*del));
		else
			ft_lstadd_back(&new, new);
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmpn = ft_lstnew((*f)(tmp->content));
		if (!tmpn)
			ft_lstclear(&tmpn, (*del));
		else
			ft_lstadd_back(&new, tmpn);
		tmp = tmp->next;
	}
	return (new);
}

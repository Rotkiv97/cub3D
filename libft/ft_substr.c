/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:08:17 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/15 17:18:52 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	char			*tmp;

	tmp = (char *)s;
	i = 0;
	if (start > ft_strlen(s))
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	while (tmp[start + i])
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (tmp[start + i] && i < len)
	{
		p[i] = tmp[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

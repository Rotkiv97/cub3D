/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:29:28 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/06 16:38:19 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(int ac, char **av)
{
	
	size_t size = 3;
	printf("%s %s ", av[1], av[2]);
	ft_strlcpy(av[1], av[2], size);
	printf("%s %s ", av[1], av[2]);
	
	char	dest[] = "ciao";
	char	src[] = "pro";
	ft_strlcpy(dest, src, 3);
	printf("%s", dest);
}
*/

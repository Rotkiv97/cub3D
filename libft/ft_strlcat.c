/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:25:06 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/14 19:16:34 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stddef.h>
#include"ft_strlen.c"
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i + 1 + j) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int main (void)
{
	char src[] = " Born to code";
    	char dest [] = "1337 42";
    	//printf("%ld \n", ft_strlcat(dest, src, 4));
    	printf("%ld \n", ft_strlcat(dest, src, 10));
    	printf("%s \n", dest);
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	
	if (!(dest = (char *)malloc(sizeof(char) * 15)))
		return (0);
	memset(dest, 'r', 15);
	printf("%ld", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);
}
*/

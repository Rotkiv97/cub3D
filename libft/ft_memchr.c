/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:03:26 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/15 17:36:10 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*p;
	unsigned char			u;

	u = (unsigned char)c;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == u)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>

int main (int argc, char argv[])
{
int arr1 [] = {3, 4}; // 0003 0004
int arr2 [] = {1, 2};    if(ft_memchr(arr2, 1, 2) != NULL)
    {
            printf("trovato il byte\n");
    }
    else
    {
            printf("non ho trovato il byte\n");
    }
    return(0);
}
*/

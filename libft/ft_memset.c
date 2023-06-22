/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:14:22 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/08 21:48:17 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}

/*
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<string.h>
int	main()
{
	
	int	v[] = {1, 2, 3, 4, 5};
	int	i = 0;

	for(int i = 0; i < 5; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
	ft_memset(v, 1, 8);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", v[i]);
		//printf("%p ", &s[i]);
	}
	
	size_t bytes = 2;
	char s[] = "ciao prova cioa";
	printf("%s\n", s);
	int c = 'z';
	int i = 0;
	ft_memset(s, c, bytes);
	printf("%s", s);
	//while (i < 5)
	//{
	//	printf("%c", s[i]);
	//	i++;
	//}
}
*/

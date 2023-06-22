/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:59 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/15 16:25:02 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
#include<stdio.h>
#include<stdlib.h>
int	main()
{
	int	*s;
	char	*p;
	int	len = 5;
	int	i = 0;
	
	s = malloc(len * sizeof(int));
	while(i < len)
	{
		s[i] = i + 1;
		i++;
	}
	for(int i = 0; i < len; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	ft_bzero(s,10);
	for(int i = 0; i < len; i++)
	{
		printf("%d ", s[i]);
		//printf("%p ", &s[i]);
	}
}
*/

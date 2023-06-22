/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:15:43 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/13 18:45:32 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

static int	ft_skip(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
		|| s[i] == '\t' || s[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *p)
{
	int	i;
	int	neg;
	int	n;

	n = 0;
	neg = 1;
	i = ft_skip(p);
	if (p[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (p[i] == '+')
		i++;
	while (p[i] >= '0' && p[i] <= '9')
	{
		n = (p[i] - 48) + (10 * n);
		i++;
	}
	n = n * neg;
	return (n);
}
/*
int	main(int ac, char **av)
{
	printf("%d", ft_atoi(av[1]));
}
*/

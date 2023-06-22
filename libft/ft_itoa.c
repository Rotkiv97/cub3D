/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:28:03 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/09 20:06:28 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long int	ft_size(long int n)
{
	long int	neg;
	long int	count;

	neg = 0;
	count = 0;
	if (n < 0)
	{
		neg = 1;
		n = n * (-1);
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count + neg);
}

static void	str_filler(char *s, long int n)
{
	long int	x;

	x = ft_size(n);
	if (n < 0)
	{
		s[0] = '-';
		n = n * (-1);
	}
	s[x] = '\0';
	x--;
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[x] = (n % 10) + 48;
		n = n / 10;
		x--;
	}
}

char	*ft_itoa(int n)
{
	char		*s;
	long int	size;
	long int	n1;

	n1 = n;
	size = ft_size(n1);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (0);
	str_filler(s, n1);
	return (s);
}
/*
int	main()
{
	printf("%s", ft_itoa(0));
}
*/

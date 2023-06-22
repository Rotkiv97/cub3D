/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:49:58 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/08 21:50:06 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	i = 0;
	if (s < d)
	{
		while (i < n)
		{
			d[n - i - 1] = s[n - i - 1];
			i++;
		}
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}

/*
int	main()
{
	char	s[] = "ciao";
	char	d[] = "wowl";

	printf("%s ", s);
	printf("%s ", d);
	ft_memmove(d, s, 4);
	//memmove(d, s, 5);
	printf("%s ", s);
	printf("%s ", d);
}
*/

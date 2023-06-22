/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:57:01 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/08 21:54:59 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*t;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		if (little[j] == big[i])
			t = &big[i];
		while ((little[j] == big[i + j]) && (big[i + j]) && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(t));
		else
			j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	char	b[] = "sadiunasciaosadjasndlk";
	char	l[] = "";
	printf("%s", ft_strnstr(b, l, 17));
}
*/

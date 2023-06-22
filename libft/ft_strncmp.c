/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:59:39 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/13 15:42:26 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((i < n - 1) && (s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main()
{
	int	i = 0;
	while(i < ft_strlen("test\200"))
	{
		printf("%d\n", "test\200"[i]);
		i++;
	}
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
}
*/

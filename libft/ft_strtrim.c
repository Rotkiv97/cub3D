/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:28:02 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 15:50:07 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	char_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i] && char_in(s[i], set))
		i++;
	return (i);
}

static int	ft_end(const char *s, const char *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i == 0)
		return (0);
	while (char_in(s[i], set) && i >= 0)
		i--;
	return (i);
}

static int	count(const char *s, const char *set)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && char_in(s[i], set))
	{
		count++;
		i++;
	}
	if (s[i] == 0)
		return (count);
	while (s[i])
		i++;
	i--;
	while (char_in(s[i], set))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s;
	int		i;
	int		j;
	int		start;
	int		end;

	j = 0;
	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	s = malloc(ft_strlen(s1) - count(s1, set) + 1);
	while (i < start)
		i++;
	while (i + j <= end)
	{
		s[j] = s1[i + j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
/*
#include<stdio.h>
int	main(int ac, char **av)
{
	printf("%s", ft_strtrim(av[1], av[2]));
}
*/

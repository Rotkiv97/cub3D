/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:33:33 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/13 18:42:33 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<stdlib.h>

static int	ischar(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

static int	count_str(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		while (s[i] && !(ischar(c, s[i])))
		{
			if (flag)
			{
				count++;
				flag = 0;
			}
			i++;
		}
		flag = 1;
		while (s[i] && ischar(c, s[i]))
			i++;
	}
	return (count);
}

static void	ft_strall(const char *s, char c, char **split)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	j = 0;
	k = 0;
	count = count_str(s, c);
	while (i < count)
	{
		while (s[j] && ischar(s[j], c))
			j++;
		while (s[j] && !(ischar(s[j], c)))
		{
			k++;
			j++;
		}
		if (k > 0)
			split[i] = (char *)malloc(sizeof(char) * (k + 1));
		k = 0;
		i++;
	}
	split[i] = 0;
}

static void	ft_str_filler(const char *s, char c, char **split)
{
	int	i;
	int	j;
	int	k;
	int	count;

	count = count_str(s, c);
	i = 0;
	j = 0;
	k = 0;
	while (i < count)
	{
		while (s[j] && ischar(s[j], c))
			j++;
		while (s[j] && !(ischar(s[j], c)))
		{
			split[i][k] = s[j];
			j++;
			k++;
		}
		split[i][k] = '\0';
		k = 0;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;

	count = count_str(s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	ft_strall(s, c, split);
	ft_str_filler(s, c, split);
	return (split);
}
/*
#include<stdio.h>

int	main(int ac, char **av)
{
	const char s[] = "ciao sono bravo ciao ciao hey";
	char	**tabstr;
	int i = 0;
	if (!(tabstr = ft_split("", 'z')))
		printf("NULL");
	else if (!tabstr[0])
		printf("ok\n");
}
*/

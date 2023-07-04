/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:25:08 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 14:47:42 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mat_len(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return (0);
	while (mat[i])
		i++;
	return (i);
}

char	**ft_copy_mat(char **mat)
{
	int		i;
	char	**cpy;

	if (!mat)
		return (0);
	cpy = (char **) malloc (sizeof(char *) * (ft_mat_len(mat) + 1));
	i = 0;
	while (mat[i])
	{
		cpy[i] = ft_strdup(mat[i]);
		i++;
	}
	return(cpy);
}

int	ft_in_set(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_close(t_program *p)
{
	ft_free_program(p);
	exit(0);
	return (0);
}
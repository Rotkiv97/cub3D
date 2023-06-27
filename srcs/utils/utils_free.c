/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:10:03 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 18:14:45 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_free_mat(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return ;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void	ft_free_program(t_program *p)
{
	ft_free_mat(p->map);
}


void	ft_free_exit(char *error, char **str)
{
	printf("\033[31m%s\033[0m\n", error);
	free(str);
	exit(0);
}

void	ft_exit(char *error)
{
	printf("\033[31m%s\033[0m\n", error);
	exit(0);
}

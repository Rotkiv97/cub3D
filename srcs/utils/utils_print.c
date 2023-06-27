/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:43:18 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/26 14:09:04 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_putstrerr(char *s)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (s)
	{
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

void	ft_print_mat(char **mat, bool new_line)
{
	int		i;

	i = 0;
	if (!mat)
		return ;
	if (new_line == true)
		while (mat[i])
			printf("%s\n", mat[i++]);
	else
		while (mat[i])
			printf("%s", mat[i++]);
}

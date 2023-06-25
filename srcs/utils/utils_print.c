/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:43:18 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 16:50:21 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:25:08 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 16:28:53 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_putstrerr(char *s)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (s)
	{
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

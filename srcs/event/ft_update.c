/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:28 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/28 17:45:36 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_update(void *p)
{
	t_program				*program;
	static long long int	i;

	program = p;
	if ((i++ % 1) == 0)
	{
		ft_ray_casting(program);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:58 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/30 20:05:14 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_draw_minimap(t_program *p)
{
	t_ivector	size;
	t_ivector	cell_size;
	int			n_cell;
	int			i;
	int			j;

	n_cell = 15;
	cell_size.x = WIDTH / 6 / n_cell;
	cell_size.y = HEIGHT / 6 / n_cell;
	size.x = n_cell * cell_size.x;
	size.y = n_cell * cell_size.y;
	i = 0;
	j = 0;

	while (i <= size.x)
	{
		j = 0;
		while (j <= size.y)
		{
			if (i == 0 || j == 0 || i == size.x || j == size.y)
				my_mlx_pixel_put(&(p->screen), i, j, 0xFF0000);
			else if (i % cell_size.x == 0 || j  % cell_size.y == 0)
				my_mlx_pixel_put(&(p->screen), i, j, 0xFF0000);
			else
				my_mlx_pixel_put(&(p->screen), i, j, 0);
			j++;
		}
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:47:43 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/10 16:10:11 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_dvector	ft_rotate_vector(t_dvector vector, double angle, bool clockwise)
{
	double		rad;
	t_dvector	new_dir;

	rad = ((double)PI / (double)180) * angle;
	if (!clockwise)
		rad = -rad;
	new_dir.x = vector.x * cos(rad) - (vector.y) * sin(rad);
	new_dir.y = vector.x * sin(rad) + (vector.y) * cos(rad);
	return (new_dir);
}

void	ft_rotate_visual(t_program *p, double angle, bool clockwise)
{
	p->player.dir = ft_rotate_vector(p->player.dir, angle, clockwise);
	p->player.cam_plane = ft_rotate_vector(p->player.cam_plane, angle, clockwise);
}
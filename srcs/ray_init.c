/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:25:50 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/07 15:48:51 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_dvector	ft_ray_direction(t_program *p, int pixel)
{
	t_dvector	ray_dir;
	double		camera;

	camera = ((2 * (double)pixel) / (double)WIDTH) - 1;
	ray_dir.x = p->player.dir.x + camera * p->player.cam_plane.x;
	ray_dir.y = p->player.dir.y + camera * p->player.cam_plane.y;
	return (ray_dir);
}

t_dvector	ft_scaling_factor(t_dvector ray_dir)
{
	t_dvector	scaling_factor;

	if (ray_dir.x == 0)
		scaling_factor.x = 1e30;
	else
		scaling_factor.x = (double)sqrt(1 + ((ray_dir.y) / (ray_dir.x)) * \
		((ray_dir.y) / (ray_dir.x)));
	if (ray_dir.y == 0)
		scaling_factor.y = 1e30;
	else
		scaling_factor.y = (double)sqrt(1 + ((ray_dir.x) / (ray_dir.y)) * \
		((ray_dir.x) / (ray_dir.y)));
	return (scaling_factor);
}

void	ft_ray_step_length(t_rayinfo *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->length1D.x = (ray->ray_start.x - (double)(ray->map_check.x)) * \
		ray->scaling_factor.x;
	}
	else
	{
		ray->step.x = 1;
		ray->length1D.x = ((double)(ray->map_check.x + 1) - ray->ray_start.x) * \
		ray->scaling_factor.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->length1D.y = (ray->ray_start.y - (double)(ray->map_check.y)) * \
		ray->scaling_factor.y;
	}
	else
	{
		ray->step.y = 1;
		ray->length1D.y = ((double)(ray->map_check.y + 1) - ray->ray_start.y) * \
		ray->scaling_factor.y;
	}
}

void	ft_init_ray(t_program *p, int pixel)
{
	t_rayinfo	*ray;

	ray = &p->ray;
	ray->pixel = pixel;
	ray->ray_dir = ft_ray_direction(p, pixel);
	ray->scaling_factor = ft_scaling_factor(ray->ray_dir);
	ray->ray_start = p->player.pos;
	ray->map_check = (t_ivector){(int)p->player.pos.x, (int)p->player.pos.y};
	ft_ray_step_length(ray);
}

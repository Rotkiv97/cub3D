/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:25 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/23 19:45:39 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	ft_distance_collision(t_program *p, t_float_vector ray_dir)
{
	bool			collision;
	float			dist_max;
	float			distance;
	t_int_vector	map_check;
	t_float_vector	scaling_factor;
	t_float_vector	ray_length1D;
	t_float_vector	step;
	t_float_vector	ray_start;
	t_float_vector	collision_point;

	ray_start = p->player.pos;
	map_check = (t_int_vector){(int)p->player.pos.x, (int)p->player.pos.y};	//check della casella in cui sono
	scaling_factor.x = (float)sqrt(1 + ((ray_dir.y) / (ray_dir.x)) * \
	((ray_dir.y) / (ray_dir.x)));
	scaling_factor.y = (float)sqrt(1 + ((ray_dir.x) / (ray_dir.y)) * \
	((ray_dir.x) / (ray_dir.y)));
	if (ray_dir.x < 0)
	{
		step.x = -1;
		ray_length1D.x = (ray_start.x - (float)(map_check.x)) * scaling_factor.x;
	}
	else
	{
		step.x = 1;
		ray_length1D.x = ((float)(map_check.x + 1) - ray_start.x) * scaling_factor.x;
	}

	if (ray_dir.y < 0)
	{
		step.y = -1;
		ray_length1D.y = (ray_start.y - (float)(map_check.y)) * scaling_factor.y;
	}
	else
	{
		step.y = 1;
		ray_length1D.y = ((float)(map_check.y + 1) - ray_start.y) * scaling_factor.y;
	}

	collision = false;
	dist_max = 100;
	while (!collision && distance < dist_max)
	{
		if (ray_length1D.x < ray_length1D.y)
		{
			map_check.x += step.x;
			distance = ray_length1D.x;
			ray_length1D.x += scaling_factor.x;
		}
		else
		{
			map_check.y += step.y;
			distance = ray_length1D.y;
			ray_length1D.y += scaling_factor.y;
		}

		if (ft_check_collision(map_check))
		{
			collision = true;
		}
	}
	if (collision)
	{
		collision_point.x = ray_start.x + ray_dir.x * distance;
		collision_point.y = ray_start.y + ray_dir.y * distance;
	}
	return (distance);
}

t_float_vector	ft_ray_direction(int ray, t_program *p)
{

}

void	ft_draw_vertical_line(t_program *p, float distance, \
t_float_vector ray_dir)
{
}

void	ft_ray_casting(t_program *p)
{
	t_float_vector	ray_dir;
	int				rays;
	float			length;

	rays = p->player.cam_plane;
	while (rays)
	{
		ray_dir = ft_ray_direction(rays, p);
		length = ft_distance_collision(p, ray_dir);
		ft_draw_vertical_line(p, length, ray_dir);
		rays--;
	}
}

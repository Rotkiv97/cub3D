/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:25 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/26 23:15:34 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_check_collision(t_program *p, t_int_vector map_check)
{
	int		x;
	int		y;
	bool	collision;
	
	collision = false;
	x = map_check.x;
	y = map_check.y;
	if(x >= 0 && y >= 0)
	{
		if (p->map[y][x] == '1')
			collision = true;
	}
	return (collision);
}

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

	(void)collision_point;
	ray_start = p->player.pos;
	map_check = (t_int_vector){(int)p->player.pos.x, (int)p->player.pos.y};	//check della casella in cui sono
	if (ray_dir.x == 0)
	{
		scaling_factor.x = 1e30;
	}
	else
	{
		scaling_factor.x = (float)sqrt(1 + ((ray_dir.y) / (ray_dir.x)) * \
	((ray_dir.y) / (ray_dir.x)));
	}
	if (ray_dir.y == 0)
	{
		scaling_factor.y = 1e30;
	}
	else
	{
		scaling_factor.y = (float)sqrt(1 + ((ray_dir.x) / (ray_dir.y)) * \
	((ray_dir.x) / (ray_dir.y)));
	}
	
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
	distance = 0;
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

		if (ft_check_collision(p, map_check))
		{
			collision = true;
			break ;
		}
	}
	if (collision)
	{
		collision_point.x = ray_start.x + ray_dir.x * distance;
		collision_point.y = ray_start.y + ray_dir.y * distance;
		//printf("collision point is x : %f |  y : %f\n", collision_point.x, collision_point.y);
	}
	return (distance);
}

t_float_vector	ft_ray_direction(int ray, t_program *p)
{
	t_float_vector	ray_dir;
	t_float_vector	p_dir;
	double			ray_angle;

	p_dir = p->player.dir;
	ray_angle = ((float)ray / p->player.n_rays * p->fov) * PI / 180;
	ray_dir.x = cos(ray_angle) * p_dir.x - sin(ray_angle) * p_dir.y;
	ray_dir.y = sin(ray_angle) * p_dir.x + cos(ray_angle) * p_dir.y;
 	return (ray_dir);
}

void	ft_draw_vertical_line(t_program *p, float distance, int ray)
{
	int		pixel;
	int		height;
	int		i;

	i = 0;
	height = (int)((distance * 300) / 3);
	pixel = (int)(((float)ray / (float)p->player.n_rays) * (float)WIDTH);
	printf("pixel : %d\n", pixel);
	while (i < height)
	{
		mlx_pixel_put(p->mlx, p->window, pixel,  ((HEIGHT - height) / 2) + i, 0x00568223);
		i++;
	}
}

void	ft_ray_casting(t_program *p)
{
	t_float_vector	ray_dir;
	int				rays;
	float			length;

	(void)length;
	rays = p->player.n_rays;
	while (rays)
	{
		ray_dir = ft_ray_direction(rays, p);
		length = ft_distance_collision(p, ray_dir);
		printf("the length of %d ray is %f\n", rays, length);
		ft_draw_vertical_line(p, length, rays);
		rays--;
	}
}

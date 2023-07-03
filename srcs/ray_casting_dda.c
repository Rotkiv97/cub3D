/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:25 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/03 19:07:45 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_check_collision(t_program *p, t_ivector map_check)
{
	int		x;
	int		y;
	bool	collision;
	
	collision = false;
	x = map_check.x;
	y = map_check.y;
	if(x >= 0 && y >= 0)
	{
		if (p->map[y][x] == '1' || p->map[y][x] == 'D')
			collision = true;
	}
	return (collision);
}

double	ft_distance_collision(t_program *p, t_dvector ray_dir)
{
	bool		collision;
	double		dist_max;
	double		distance;
	t_ivector	map_check;
	t_dvector	scaling_factor;
	t_dvector	ray_length1D;
	t_dvector	step;
	t_dvector	ray_start;

	p->side = -1;
	ray_start = p->player.pos;
	map_check = (t_ivector){(int)p->player.pos.x, (int)p->player.pos.y};	//salvo la casella in cui e' presente il player
	if (ray_dir.x == 0)
		scaling_factor.x = 1e30;
	else
	{
		scaling_factor.x = (double)sqrt(1 + ((ray_dir.y) / (ray_dir.x)) * \
		((ray_dir.y) / (ray_dir.x)));
	}
	if (ray_dir.y == 0)
		scaling_factor.y = 1e30;
	else
	{
		scaling_factor.y = (double)sqrt(1 + ((ray_dir.x) / (ray_dir.y)) * \
		((ray_dir.x) / (ray_dir.y)));
	}
	if (ray_dir.x < 0)
	{
		step.x = -1;
		ray_length1D.x = (ray_start.x - (double)(map_check.x)) * scaling_factor.x;
	}
	else
	{
		step.x = 1;
		ray_length1D.x = ((double)(map_check.x + 1) - ray_start.x) * scaling_factor.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		ray_length1D.y = (ray_start.y - (double)(map_check.y)) * scaling_factor.y;
	}
	else
	{
		step.y = 1;
		ray_length1D.y = ((double)(map_check.y + 1) - ray_start.y) * scaling_factor.y;
	}
	collision = false;
	distance = 0;
	dist_max = 100;
	while (!collision && distance < dist_max)
	{
		if (ray_length1D.x < ray_length1D.y)
		{
			p->side = 0;
			map_check.x += step.x;
			distance = ray_length1D.x;
			ray_length1D.x += scaling_factor.x;
		}
		else
		{
			p->side = 1;
			map_check.y += step.y;
			distance = ray_length1D.y;
			ray_length1D.y += scaling_factor.y;
		}
		if (ft_check_collision(p, map_check))
		{
			collision = true;
			p->map_check.x = map_check.x;
			p->map_check.y = map_check.y;
			break ;
		}
	}
	 if(p->side == 0)
		distance = fabs((map_check.x - ray_start.x + (1 - step.x) / 2) / ray_dir.x);
	else
		distance = fabs((map_check.y - ray_start.y + (1 - step.y) / 2) / ray_dir.y);
	return (distance);
}

t_dvector	ft_ray_direction(int pixel, t_program *p)
{
	t_dvector	ray_dir;
	double		cameraX;

	cameraX = ((2 * (double)pixel) / (double)WIDTH) - 1;
	ray_dir.x = p->player.dir.x + cameraX * p->player.cam_plane.x;
	ray_dir.y = p->player.dir.y + cameraX * p->player.cam_plane.y;
 	return (ray_dir);
}

int		ft_pick_texture(t_program *p, int side_coll)
{
	int		text;

	text = 0;
	if (side_coll == 1 && p->ray_dir.y <= 0)
		text = 0;
	else if (side_coll == 1 && p->ray_dir.y > 0)
		text = 1;
	else if (side_coll == 0 && p->ray_dir.x < 0)
		text = 2;
	else if (side_coll == 0 && p->ray_dir.x >= 0)
		text = 3;
	if (p->map[p->map_check.y][p->map_check.x] == 'D')
		text = 6;
	return (text);
}

int	ft_color_texture(t_img texture, int x, int y)
{
	int		color;
	char	*dst;

	dst = texture.addr + ((y) * texture.line_length + x * (texture.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	ft_draw_texture(t_program *p, double distance, int pixel)
{
	double	wall_hit;
	int		text_x;
	int		text_y;
	int		texture;
	double	height;
	double	text_pos;
	int		i;
	int		plus;

	texture = ft_pick_texture(p, p->side);
	if (p->side == 0)
		wall_hit = p->player.pos.y + distance * p->ray_dir.y;
	else
		wall_hit = p->player.pos.x + distance * p->ray_dir.x;
	wall_hit -= floor(wall_hit);
	text_x = (int) (wall_hit * (double)p->textures[texture].width);
	if (p->side == 0 && p->ray_dir.x > 0)
		text_x = p->textures[texture].width - text_x - 1;
	if (p->side == 1 && p->ray_dir.y < 0)
		text_x = p->textures[texture].width - text_x - 1;
	i = 0;
	height = abs((int)((double)HEIGHT / distance));
	plus = 0;
	if (height >= HEIGHT)
	{
		plus = height - HEIGHT;
		height = HEIGHT;
	}
	while (i <= height)
	{
		text_pos = (double)(((double)i + (double)plus / 2) * (double)p->textures[texture].height / (double)(height + plus));
		text_y = (int)round(text_pos) & (p->textures[texture].height - 1);
		my_mlx_pixel_put(&(p->screen), pixel, (HEIGHT - height)/2 + i, \
		ft_color_texture(p->textures[texture], text_x, text_y));
		i++;
	}
	plus = plus;
}

void	ft_ray_casting(t_program *p)
{
	int			pixel;
	double		distance;

	pixel = 0;
	p->side = -1;
	ft_background(p);
	while (pixel < WIDTH)
	{
		p->ray_dir = ft_ray_direction(pixel, p);
		distance = ft_distance_collision(p, p->ray_dir);
		ft_draw_texture(p, distance, pixel);
		//ft_draw_vertical_line(p, distance, pixel, *side_coll);
		pixel++;
	}
	ft_draw_minimap(p);
	mlx_put_image_to_window(p->mlx, p->window, p->screen.img, 0, 0);
}

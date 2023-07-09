/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:20:24 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/09 21:07:07 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*ft_portal(t_program *p)
{
	static unsigned long int	last;

	(void)last;
	if (p->player.interact)
	{
		return (&p->sprites.portal[1]);
	}
	else
	{
		return (&p->sprites.door);
	}
	return (0);
}

t_img	*ft_pick_texture(t_program *p)
{
	int	side_coll;

	side_coll = p->ray.side;
	if (p->map[p->ray.map_check.y][p->ray.map_check.x] == 'D')
		return (&p->sprites.door);
	if (p->ray.collision == 'L')
		return (&p->sprites.portal[1]);
	if (side_coll == 1 && p->ray.ray_dir.y <= 0)
		return (&p->sprites.north);
	if (side_coll == 1 && p->ray.ray_dir.y > 0)
		return (&p->sprites.south);
	if (side_coll == 0 && p->ray.ray_dir.x < 0)
		return (&p->sprites.east);
	if (side_coll == 0 && p->ray.ray_dir.x >= 0)
		return (&p->sprites.west);
	return (0);
}

unsigned int	ft_color_texture(t_program *p, t_img texture, t_ivector pixels, bool darker)
{
	unsigned int		color;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	double				scaling_factor;
	char				*dst;

	if (!texture.img)
		return (0);
	if (p->ray.perp_distance < 0.5)
		scaling_factor = 1;
	else
		scaling_factor = 1 / (p->ray.perp_distance * 2);
	dst = texture.addr + ((pixels.y) * texture.line_length + pixels.x * \
	(texture.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	if (darker)
	{
		r = (color >> 16) & 0xFF;
		r = (unsigned char)(r * scaling_factor);
		g = (color >> 8) & 0xFF;
		g = (unsigned char)(g * scaling_factor);
		b = color & 0xFF;
		b = (unsigned char)(b * scaling_factor);
		return ((r << 16) | (g << 8) | b);
	}
	return (color);
}

int	ft_return_textx(t_program *p, t_img *texture)
{
	double	wall_hit;
	int		text_x;

	if (p->ray.side == 0)
		wall_hit = p->player.pos.y + p->ray.perp_distance * p->ray.ray_dir.y;
	else
		wall_hit = p->player.pos.x + p->ray.perp_distance * p->ray.ray_dir.x;
	wall_hit -= floor(wall_hit);
	text_x = (int)(wall_hit * (double)texture->width);
	if (p->ray.side == 0 && p->ray.ray_dir.x > 0)
		text_x = (double)texture->width - text_x - 1;
	if (p->ray.side == 1 && p->ray.ray_dir.y < 0)
		text_x = (double)texture->width - text_x - 1;
	return (text_x);
}

int	ft_return_texty(t_img *texture, int i, int plus, int height)
{
	int	texty;

	texty = (int)round((double)(((double)i + (double)plus / 2) * \
	(double)texture->height / (double)(height + plus))) & \
	(texture->height - 1);
	return (texty);
}

void	ft_draw_texture(t_program *p, int pixel)
{
	t_img		*texture;
	t_ivector	text;
	int			i;
	int			plus;

	texture = ft_pick_texture(p);
	if (!texture || !texture->img)
		return ;
	i = 0;
	p->ray.height = abs((int)((double)HEIGHT / p->ray.perp_distance));
	plus = 0;
	if (p->ray.height >= HEIGHT)
	{
		plus = p->ray.height - HEIGHT;
		p->ray.height = HEIGHT;
	}
	text.x = ft_return_textx(p, texture);
	while (i <= p->ray.height)
	{
		text.y = ft_return_texty(texture, i, plus, p->ray.height);
		my_mlx_pixel_put(&(p->screen), pixel, (HEIGHT - p->ray.height) / 2 + i, \
		ft_color_texture(p, *texture, (t_ivector){text.x, text.y}, false));
		i++;
	}
}

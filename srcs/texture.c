/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:20:24 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/07 16:13:53 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*ft_pick_texture(t_program *p)
{
	int	side_coll;

	side_coll = p->ray.side;
	if (p->map[p->ray.map_check.y][p->ray.map_check.x] == 'D')
		return (&p->sprites.door);
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

int	ft_color_texture(t_img texture, int x, int y)
{
	int		color;
	char	*dst;

	dst = texture.addr + ((y) * texture.line_length + x * \
	(texture.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
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
	int			height;
	int			plus;

	texture = ft_pick_texture(p);
	if (!texture)
		return ;
	i = 0;
	height = abs((int)((double)HEIGHT / p->ray.perp_distance));
	plus = 0;
	if (height >= HEIGHT)
	{
		plus = height - HEIGHT;
		height = HEIGHT;
	}
	text.x = ft_return_textx(p, texture);
	while (i <= height)
	{
		text.y = ft_return_texty(texture, i, plus, height);
		my_mlx_pixel_put(&(p->screen), pixel, (HEIGHT - height) / 2 + i, \
		ft_color_texture(*texture, text.x, text.y));
		i++;
	}
}

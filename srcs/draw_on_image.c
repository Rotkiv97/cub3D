/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:35:43 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/08 18:41:01 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_transp(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (color > 0)
		*(unsigned int*)dst = color;
}

void	ft_draw_animation(t_program *p)
{
	static int				an;
	static int		easter_egg;

	if (ft_check_movement(p))
	{
		if (p->frame % 3 == 0)
			ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[an++]);
		else
			ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[an]);
		if (an > 8)
			an = 0;
	}
	else
	{
		ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[4]);
	}
	if (p->player.easter_egg && easter_egg < 4)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.easter_egg[easter_egg++]);
	else if (p->player.easter_egg)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.easter_egg[3]);
	else
		easter_egg = 0;
}

void	ft_fill_texture(t_program *p, t_ivector position, t_ivector size, t_img texture)
{
	int	x;
	int	y;
	int	textx;
	int	texty;

	if (!texture.img)
		return ;
	x = 0;
	y = 0;
	if (position.x + size.x > WIDTH || position.y + size.y > HEIGHT)
		return ;
	while (x <= size.x)
	{
		textx = (int)((x) * (double)texture.width / size.x);
		y = 0;
		while (y <= size.y)
		{
			texty = (int)((y) * (double)texture.height / size.y);
			my_mlx_pixel_put_transp(&(p->screen), position.x + x, position.y + y, ft_color_texture(p, texture, (t_ivector){textx, texty}, false));
			y++;
		}
		x++;
	}
}

void	ft_background(t_program *p, int pixel)
{
	int		line;
	int		i;

	i = 0;
	line = (HEIGHT - p->ray.height) / 2;
	while (i <= line)
	{
		my_mlx_pixel_put(&p->screen, pixel, i, p->ceil_color);
		i++;
	}
	while (line >= 0)
	{
		my_mlx_pixel_put(&p->screen, pixel, HEIGHT - line, p->floor_color);
		line--;
	}
}

// 680 : 600
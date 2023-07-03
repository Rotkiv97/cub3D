/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:35:43 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/03 20:05:54 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_ceiling(t_program *p)
{
	t_img	ceil;
	int		x;
	int		y;
	int		textx;
	int		texty;

	x = 0;
	y = 0;
	ceil = p->textures[4];
	if (!ceil.img)
	{
		ft_fill_cell_minimap(p, (t_ivector){0, 0}, (t_ivector){WIDTH, HEIGHT / 2}, CTEXT);
		return ;
	}
	while (x < WIDTH)
	{
		textx = (int)(x * (double)ceil.width / (double)WIDTH);
		y = 0;
		while (y <= HEIGHT / 2)
		{
			texty = (int)(y * (double)ceil.height / (double)(HEIGHT / 2.0));
			my_mlx_pixel_put(&(p->screen), x, y, ft_color_texture(ceil, textx, texty));
			y++;
		}
		x++;
	}
}

void	ft_draw_floor(t_program *p)
{
	t_img	floor;
	int		x;
	int		y;
	int		textx;
	int		texty;

	x = 0;
	y = HEIGHT / 2;
	floor = p->textures[5];
	if (!floor.img)
	{
		ft_fill_cell_minimap(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH, HEIGHT / 2}, FTEXT);
		return ;
	}
	while (x < WIDTH)
	{
		textx = (int)(x * (double)floor.width / (double)WIDTH);
		y = HEIGHT / 2;
		while (y <= HEIGHT)
		{
			texty = (int)(y * (double)floor.height / (double)(HEIGHT));
			my_mlx_pixel_put(&(p->screen), x, y, ft_color_texture(floor, textx, texty));
			y++;
		}
		x++;
	}
}

void	ft_background(t_program *p)
{
	ft_fill_cell_minimap(p, (t_ivector){0, 0}, (t_ivector){WIDTH, HEIGHT}, 0);
	ft_draw_ceiling(p);
	//ft_draw_floor(p);
}

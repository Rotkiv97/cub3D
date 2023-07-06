/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:35:43 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/06 18:47:10 by dcolucci         ###   ########.fr       */
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
			my_mlx_pixel_put_transp(&(p->screen), position.x + x, position.y + y, ft_color_texture(texture, textx, texty));
			y++;
		}
		x++;
	}
}

void	ft_background(t_program *p)
{
	if (p->ceil_color == 0 && p->sprites.ceiling.img)
		ft_fill_texture(p, (t_ivector){0, 0}, (t_ivector){WIDTH, HEIGHT / 2}, p->sprites.ceiling);
	else
		ft_fill_cell_minimap(p, (t_ivector){0, 0}, (t_ivector){WIDTH, HEIGHT / 2}, p->ceil_color);
	if (p->floor_color == 0 && p->sprites.floor.img)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH, HEIGHT / 2}, p->sprites.floor);
	else
		ft_fill_cell_minimap(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH, HEIGHT / 2}, p->floor_color);
}

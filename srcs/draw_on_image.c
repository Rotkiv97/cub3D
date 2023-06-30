/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:35:43 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/30 17:09:24 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_black_screen(t_program *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&(p->screen), j, i, 0);
			j++;
		}
		i++;
	}
}

void	ft_background(t_program *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&(p->screen), j, i, CTEXT);
			j++;
		}
		i++;
	}
	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&(p->screen), j, i, FTEXT);
			j++;
		}
		i++;
	}
}

int		ft_set_wesn_color(t_program *p, int side_coll)
{
	int		color;

	color = 0;
	if (side_coll == 0 && p->ray_dir.x < 0)
		color = ETEXT;
	else if (side_coll == 0 && p->ray_dir.x >= 0)
		color = WTEXT;
	else if (side_coll == 1 && p->ray_dir.y > 0)
		color = STEXT;
	else if (side_coll == 1 && p->ray_dir.y <= 0)
		color = NTEXT;
	return (color);
}

void	ft_draw_vertical_line(t_program *p, double distance, int pixel, int side_coll)
{
	int			i;
	int			height;
	int			color;
	i = 0;
	color = ft_set_wesn_color(p, side_coll);
	height = abs((int)((double)HEIGHT / distance));
	if (height >= HEIGHT)
		height = HEIGHT;
	while (i < height)
	{
		my_mlx_pixel_put(&(p->screen), pixel, (int)((HEIGHT - height)/2) + i, color);
		i++;
	}
}

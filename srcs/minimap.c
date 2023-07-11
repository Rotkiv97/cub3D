/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:58 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 12:16:07 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_fill_cell_minimap(t_program *p, t_ivector position, \
t_ivector cell_size, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= cell_size.x)
	{
		j = 0;
		while (j <= cell_size.y)
		{
			my_mlx_pixel_put(&(p->screen), i + position.x, j + \
			position.y, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_arrow(t_program *p, t_ivector position, t_ivector size)
{
	static int			texture;
	t_dvector			d;

	d = (t_dvector){p->player.dir.x, p->player.dir.y};
	if (d.x > 0.86602540378)
		texture = 2;
	else if (d.x < 0.86602540378 && d.x > 0.5 && d.y > 0)
		texture = 3;
	else if (d.x < 0.86602540378 && d.x > 0.5 && d.y <= 0)
		texture = 1;
	else if (d.x >= 0 && d.x < 0.5 && d.y > 0)
		texture = 4;
	else if (d.x >= 0 && d.x < 0.5 && d.y <= 0)
		texture = 0;
	else if (d.x < -0.86602540378)
		texture = 6;
	else if (d.x > -0.86602540378 && d.x < -0.5 && d.y > 0)
		texture = 5;
	else if (d.x > -0.86602540378 && d.x < -0.5 && d.y <= 0)
		texture = 7;
	else if (d.x < 0 && d.x > -0.5 && d.y > 0)
		texture = 4;
	else if (d.x < 0 && d.x > -0.5 && d.y <= 0)
		texture = 0;
	ft_fill_texture(p, position, size, p->sprites.arrow[texture]);
}

unsigned int	ft_color_square(t_program *p, t_ivector iterator, int mat_len)
{
	unsigned int	color;

	color = 0;
	if ((iterator.y < 0 || iterator.y > mat_len - 1) || (iterator.x < 0 || \
		iterator.x > (int)ft_strlen(p->map[iterator.y]) - 1) || \
		(ft_in_set(p->map[iterator.y][iterator.x], "1\n\t\0 ")))
		color = 0x006600;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "0NWES"))
		color = 0;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "D"))
		color = 0xFF0000;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "O"))
		color = 0x00FF00;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "L"))
		color = 0xFFFF33;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "P"))
		color = 0x0000FF;
	else if (ft_in_set(p->map[iterator.y][iterator.x], "U"))
		color = 0xFFFFFF;
	return (color);
}

void	ft_cicle_squares_minimap(t_program *p, int n_cell, \
t_ivector iterator, t_ivector cell_size)
{
	unsigned int	color;
	t_ivector		i;
	int				mat_len;

	mat_len = ft_mat_len(p->map);
	i = (t_ivector){0, 0};
	while (i.x < n_cell)
	{
		i.y = 0;
		while (i.y < n_cell)
		{
			color = ft_color_square(p, iterator, mat_len);
			ft_fill_cell_minimap(p, (t_ivector){i.y * cell_size.x, \
			i.x * cell_size.y}, cell_size, color);
			if (iterator.x == (int)p->player.pos.x && \
			iterator.y == (int)p->player.pos.y)
				ft_draw_arrow(p, (t_ivector){i.y * cell_size.x, i.x * \
			cell_size.y}, (t_ivector){cell_size.x, cell_size.y});
			iterator.x++;
			i.y++;
		}
		iterator.x = (int)p->player.pos.x - n_cell / 2;
		iterator.y++;
		i.x++;
	}
}

void	ft_draw_minimap(t_program *p)
{
	t_ivector	cell_size;
	t_ivector	iterator;
	int			n_cell;

	n_cell = 11;
	cell_size.x = WIDTH / 7 / n_cell;
	cell_size.y = HEIGHT / 7 / n_cell;
	iterator = (t_ivector){(int)p->player.pos.x - n_cell / 2, \
	(int)p->player.pos.y - n_cell / 2};
	ft_cicle_squares_minimap(p, n_cell, iterator, cell_size);
}

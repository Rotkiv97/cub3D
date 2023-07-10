/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:58 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/10 16:03:26 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_fill_cell_minimap(t_program *p, t_ivector position, t_ivector cell_size, int color)
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
			my_mlx_pixel_put(&(p->screen), i + position.x, j + position.y, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_arrow(t_program *p, t_ivector position, t_ivector size)
{
	static int			texture;
 	t_dvector	d;

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

void	ft_draw_walls_minimap(t_program *p, t_ivector cell_size, int n_cell)
{
	int			i;
	int			j;
	t_ivector	n_position;
	t_ivector	iterator;
	int			mat_len;

	(void)n_cell;
	(void)cell_size;
	mat_len = ft_mat_len(p->map);
	n_position = (t_ivector){(int)p->player.pos.x, (int)p->player.pos.y};
	iterator = (t_ivector){n_position.x - n_cell / 2, n_position.y - n_cell / 2};
	i = 0;
	j = 0;
	while (i < n_cell)
	{
		j = 0;
		while (j < n_cell)
		{
			if (iterator.y < 0 || iterator.y > mat_len - 1)
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0x006600);
			else if (iterator.x < 0 || iterator.x > (int)ft_strlen(p->map[iterator.y]) - 1)
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0x006600);
			else if (ft_in_set(p->map[iterator.y][iterator.x], "1\n\t\0 "))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0x006600);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "0N"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "D"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0xFF0000);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "O"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0x00FF00);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "L"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0xFFFF33);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "P"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0x0000FF);
			else if(ft_in_set(p->map[iterator.y][iterator.x], "U"))
				ft_fill_cell_minimap(p, (t_ivector){j * cell_size.x, i * cell_size.y}, cell_size, 0xFFFFFF);
			if (iterator.x == (int)p->player.pos.x && iterator.y == (int)p->player.pos.y)
				ft_draw_arrow(p, (t_ivector){j * (int)((double)cell_size.x ), i * (int)((double)cell_size.y)}, (t_ivector){cell_size.x, cell_size.y});
			iterator.x++;
			j++;
		}
		iterator.x = n_position.x - n_cell / 2;
		iterator.y++;
		i++;
	}
}

void	ft_draw_border(t_program *p, int sizex, int sizey)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= sizex)
	{
		y = 0;
		while (y <= sizey)
		{
			if (x == 0 || y == 0 || x == sizex || y == sizey)
				my_mlx_pixel_put(&(p->screen), x, y, 0);
			y++;
		}
		x++;
	}
}

void	ft_draw_minimap(t_program *p)
{
	t_ivector	cell_size;
	int			n_cell;

	n_cell = 11;
	cell_size.x = WIDTH / 7  / n_cell;
	cell_size.y = HEIGHT  / 7 / n_cell;
	ft_draw_walls_minimap(p, cell_size, n_cell);
	//ft_draw_border(p, cell_size.x * n_cell, cell_size.y * n_cell);
}

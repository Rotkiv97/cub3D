/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 12:02:59 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_movement(t_program *p, int key)
{
	if (key == W)
		p->player.moving_up = true;
	else if (key == S)
		p->player.moving_down = true;
	else if (key == A)
		p->player.moving_left = true;
	else if (key == D)
		p->player.moving_rigth = true;
	p->player.moving = true;
}

void	ft_interact(t_program *p)
{
	t_dvector	new_position;

	p->player.interact = true;
	new_position.x = p->player.pos.x + p->player.dir.x;
	new_position.y = p->player.pos.y + p->player.dir.y;
	if (p->map[(int)new_position.y][(int)new_position.x] == 'D')
		p->map[(int)new_position.y][(int)new_position.x] = 'O';
	else if (p->map[(int)new_position.y][(int)new_position.x] == 'O')
		p->map[(int)new_position.y][(int)new_position.x] = 'D';
}

int	ft_input(int key, void *program)
{
	t_program	*p;

	p = program;
	if (key == PAUSE && p->pause == 0)
		p->pause = 1;
	else if (key == PAUSE && p->pause == 1)
	{
		mlx_mouse_move(p->mlx, p->window, WIDTH / 2, HEIGHT / 2);
		p->pause = 0;
	}
	if (key == ESC)
		ft_close(p);
	if (p->pause == 1)
		return (0);
	if (key == Q)
		p->player.easter_egg = true;
	if ((key == W || key == S || key == D || key == A))
		ft_set_movement(p, key);
	if (key == E)
		ft_interact(p);
	if (key == RIGHT)
		p->player.rotating_rigth = true;
	if (key == LEFT)
		p->player.rotating_left = true;
	return (0);
}

int	ft_close(t_program *p)
{
	mlx_do_key_autorepeaton(p->mlx);
	ft_free_program(p);
	exit(0);
	return (0);
}

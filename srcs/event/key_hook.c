/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/08 17:17:18 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_open_door(t_program *p)
{
	t_dvector	new_position;

	new_position.x = p->player.pos.x + p->player.dir.x;
	new_position.y = p->player.pos.y + p->player.dir.y;
	if (p->map[(int)new_position.y][(int)new_position.x] == 'D')
	{
		p->map[(int)new_position.y][(int)new_position.x] = 'O';
	}
	else if (p->map[(int)new_position.y][(int)new_position.x] == 'O')
	{
		p->map[(int)new_position.y][(int)new_position.x] = 'D';
	}
}

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

bool	ft_check_movement(t_program *p)
{
	bool	moving;
	
	moving = false;
	if (p->player.moving_down || p->player.moving_left || p->player.moving_rigth \
	|| p->player.moving_up)
		moving = true;
	return (moving);
}

int	ft_input_release(int key, void *program)
{
	t_program	*p;

	p = (t_program *)program;
	if (key == W)
		p->player.moving_up = false;
	if (key == S)
		p->player.moving_down = false;
	if (key == A)
		p->player.moving_left = false;
	if (key == D)
		p->player.moving_rigth = false;
	if (!ft_check_movement(p))
		p->player.moving = false;
	if (key == Q)
		p->player.easter_egg = false;
	return (0);
}

int	ft_input(int key, void *program)
{
	t_program	*p;

	p = program;
	if (key == PAUSE && p->pause == 0)
	{
		mlx_mouse_show(p->mlx, p->window);
		p->pause = 1;
	}
	else if (key == PAUSE && p->pause == 1)
	{
		mlx_mouse_move(p->mlx, p->window, WIDTH / 2, HEIGHT / 2);
		p->pause = 0;
	}
	if (key == ESC)
		ft_close(p);
	if (key == Q)
		p->player.easter_egg = true;
	if (p->pause == 1)
		return (0);
	if (key == W || key == S || key == D || key == A)
		ft_set_movement(p, key);
	if (key == E)
		ft_open_door(p);
	if (key == LEFT)
		ft_rotate_visual(p, 5, false);
	if (key == RIGHT)
		ft_rotate_visual(p, 5, true);
	return (0);
}

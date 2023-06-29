/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/29 15:40:14 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_player(t_program *p, int key)
{
	t_dvector	new_position;

	if (key == W)	
	{
		new_position.x = p->player.pos.x + p->player.dir.x * (double)MOVESPEED;
		new_position.y = p->player.pos.y + p->player.dir.y * (double)MOVESPEED;
	}
	else if (key == S)
	{
		new_position.x = p->player.pos.x - p->player.dir.x * (double)MOVESPEED;
		new_position.y = p->player.pos.y - p->player.dir.y * (double)MOVESPEED;
	}
	else if(key == D)
	{
		new_position.x = p->player.pos.x - p->player.dir.y * (double)MOVESPEED;
		new_position.y = p->player.pos.y + p->player.dir.x * (double)MOVESPEED;
	}
	else if (key == A)
	{
		new_position.x = p->player.pos.x + p->player.dir.y * (double)MOVESPEED;
		new_position.y = p->player.pos.y - p->player.dir.x * (double)MOVESPEED;
	}
	if (p->map[(int)new_position.y][(int)new_position.x] == '1')
		return ;
	p->player.pos.x = new_position.x;
	p->player.pos.y = new_position.y;
}

int	ft_input(int key, void *program)
{
	t_program	*p;

	p = program;
	if (key == PAUSE)
	{
		if (p->pause == 0)
		{
			mlx_mouse_show(p->mlx, p->window);
			p->pause = 1;
		}
		else
		{
			mlx_mouse_hide(p->mlx, p->window);
			p->pause = 0;
		}
	}
	if (key == ESC)
		exit(0);
	if (p->pause == 1)
		return (0);
	if (key == W || key == S || key == D || key == A)
	{
		ft_move_player(p, key);
	}
	if (key == LEFT)
		ft_rotate_visual(p, 5, false);
	if (key == RIGHT)
		ft_rotate_visual(p, 5, true);
	return (0);
}

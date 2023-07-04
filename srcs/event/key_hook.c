/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 14:50:32 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_check_move(t_dvector new_pos, t_program *p, t_dvector mov_dir)
{
	double		collision_distance;

	mov_dir.x = new_pos.x - p->player.dir.x;
	mov_dir.y = new_pos.y - p->player.dir.y;
	collision_distance = ft_distance_collision(p, mov_dir);
	collision_distance = collision_distance;
	return (0);
}

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
	if (p->map[(int)new_position.y][(int)new_position.x] == '1' || \
	p->map[(int)new_position.y][(int)new_position.x] == 'D')
		return ;
	p->player.pos.x = new_position.x;
	p->player.pos.y = new_position.y;
}

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

int	ft_input(int key, void *program)
{
	t_program	*p;

	p = program;
	//printf("key : %d\n", key);
	if (key == PAUSE)
	{
		if (p->pause == 0)
		{
			mlx_mouse_show(p->mlx, p->window);
			p->pause = 1;
		}
		else
		{
			//mlx_mouse_hide(p->mlx, p->window);
			p->pause = 0;
		}
	}
	if (key == ESC)
		ft_close(p);
	if (p->pause == 1)
		return (0);
	if (key == W || key == S || key == D || key == A)
		ft_move_player(p, key);
	if (key == E)
		ft_open_door(p);
	if (key == LEFT)
		ft_rotate_visual(p, 5, false);
	if (key == RIGHT)
		ft_rotate_visual(p, 5, true);
	return (0);
}

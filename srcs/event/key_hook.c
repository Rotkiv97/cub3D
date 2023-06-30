/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/30 20:06:18 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_check_move(t_dvector new_pos, t_program *p, t_dvector mov_dir)
{
	//double		new_distance;
	double		collision_distance;
	int			a;

	mov_dir.x = new_pos.x - p->player.dir.x;
	mov_dir.y = new_pos.y - p->player.dir.y;
	//new_distance = sqrt(pow(new_pos.y - p->player.pos.y, 2) + pow(new_pos.x - p->player.pos.x, 2));
	collision_distance = ft_distance_collision(p, mov_dir, &a);
	//printf("collision_distance = %f and new_distance = %f\n", collision_distance, new_distance);
	/* if (new_distance > collision_distance)
		return (1); */
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
	if (p->map[(int)new_position.y][(int)new_position.x] == '1')
		return ;
	p->player.pos.x = new_position.x;
	p->player.pos.y = new_position.y;
	//printf("Player position :");
	//ft_print_vector(&p->player.pos, true);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:58:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/28 21:38:05 by dcolucci         ###   ########.fr       */
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
	if (p->map[(int)new_position.y][(int)new_position.x] == '1')
		return ;
	p->player.pos.x = new_position.x;
	p->player.pos.y = new_position.y;
}

int	ft_input(int key, void *program)
{
	t_program	*p;

	p = program;
	(void)p;
	if (key == W || key == S)
		ft_move_player(p, key);
	if (key == LEFT)
		ft_rotate_visual(p, 5, false);
	if (key == RIGHT)
		ft_rotate_visual(p, 5, true);
	if (key == ESC)
		exit(0);
	return (0);
}
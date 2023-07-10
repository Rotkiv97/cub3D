/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:05:41 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/10 17:18:03 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_check_movement(t_program *p)
{
	bool	moving;
	
	moving = false;
	if (p->player.moving_down || p->player.moving_left || p->player.moving_rigth \
	|| p->player.moving_up)
		moving = true;
	return (moving);
}

void	ft_check_portal(t_program *p)
{
	int		i;
	int		j;

	if (p->sprites.current_portal != 7)
	{
		p->sprites.current_portal = 0;
		return ;
	}
	if (p->sprites.easter_done)
		return;
	i = 0;
	j = 0;
	p->sprites.easter_done = true;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P' || p->map[i][j] == 'L')
				p->map[i][j] = '0';
			j++;
		}
		i++;
	}
	usleep(500000);
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
	if (key == E)
	{
		p->player.interact = false;
		ft_check_portal(p);
	}
	if (key == RIGHT)
		p->player.rotating_rigth = false;
	if (key == LEFT)
		p->player.rotating_left = false;
	return (0);
}
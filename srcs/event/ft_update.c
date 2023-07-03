/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:28 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/03 20:16:23 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_mouse_visual(t_program *program, int frame)
{
	t_ivector				new_mouse;

	if (program->pause == 0)
	{	
		mlx_mouse_hide(program->mlx, program->window);
		mlx_mouse_get_pos(program->mlx, program->window, \
		&new_mouse.x, &new_mouse.y);
		if (program->mouse.x < new_mouse.x)
		{
			ft_rotate_visual(program, 3 * ROTSPEED, true);
			ft_ray_casting(program);
		}
		else if (program->mouse.x > new_mouse.x)
		{
			ft_rotate_visual(program, 3 * ROTSPEED, false);
			ft_ray_casting(program);
		}
		program->mouse.x = new_mouse.x;
		program->mouse.y = new_mouse.y;
		(void)frame;
		/* if (frame % 10 == 0)
		{
			program->mouse.x = WIDTH /2;
			program->mouse.y = HEIGHT/2;
			mlx_mouse_move(program->mlx, program->window, program->mouse.x, program->mouse.y);
			ft_ray_casting(program);
		} */
	}
}

int	ft_update(void *p)
{
	t_program				*program;
	static long long int	i;

	program = p;
	ft_mouse_visual(program, i++);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:28 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 17:48:47 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

long int	ft_return_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_mouse_visual(t_program *program, int frame)
{
	t_ivector				new_mouse;

	if (program->pause == 0)
	{
		//mlx_mouse_hide(program->mlx, program->window);
		mlx_mouse_get_pos(program->mlx, program->window, \
		&new_mouse.x, &new_mouse.y);
		if (program->mouse.x < new_mouse.x)
			ft_rotate_visual(program, ROTSPEED * (new_mouse.x - program->mouse.x) * 0.1, true);
		else if (program->mouse.x > new_mouse.x)
			ft_rotate_visual(program, ROTSPEED * (program->mouse.x - new_mouse.x) * 0.1, false);
		program->mouse.x = new_mouse.x;
		program->mouse.y = new_mouse.y;
		ft_ray_casting(program);
		if (frame % 15 == 0)
		{
			program->mouse.x = WIDTH /2;
			program->mouse.y = HEIGHT/2;
			mlx_mouse_move(program->mlx, program->window, program->mouse.x, program->mouse.y);
		}
	}
}

int	ft_update(void *p)
{
	t_program				*program;
	static long long int	i;
	time_t					time_s;
	time_t					time_e;
	double					fps;

	time_s = ft_return_time();
	program = p;
	ft_mouse_visual(program, i++);
	time_e = ft_return_time();
	fps = ((time_e - time_s) * (double)1000.0);
	printf("FPS : %f\n", fps);
	return (0);
}
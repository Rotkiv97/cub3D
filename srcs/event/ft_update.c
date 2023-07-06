/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:28 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/06 11:06:31 by dcolucci         ###   ########.fr       */
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
		if (frame % 15 == 0)
		{
			program->mouse.x = WIDTH /2;
			program->mouse.y = HEIGHT/2;
			mlx_mouse_move(program->mlx, program->window, program->mouse.x, program->mouse.y);
		}
	}
}

void	ft_fps(t_program *p, time_t start, time_t end)
{
	int		fps;
	char	*itoa;
	char	*tmp;

	fps = (int)((double)1000 / (end - start));
	itoa = ft_itoa(fps);
	tmp = ft_strjoin("FPS : ", itoa);
	mlx_string_put(p->mlx, p->window, WIDTH / 2, HEIGHT / 50, 0xFF00000, tmp);
	free(itoa);
	free(tmp);
}

t_dvector	ft_set_new_dir(t_program *p)
{
	t_player	pl;
	t_dvector	dir;

	pl = p->player;
	if (pl.moving_down && pl.moving_up && pl.moving_left && pl.moving_rigth)
		dir = (t_dvector){0, 0};
	else if (pl.moving_down && pl.moving_up && pl.moving_left)
		dir = ft_rotate_vector(pl.dir, 90, false);
	else if (pl.moving_up && pl.moving_left && pl.moving_rigth)
		dir = pl.dir;
	else if (pl.moving_down && pl.moving_left && pl.moving_rigth)
		dir = ft_rotate_vector(pl.dir, 180, true);
	else if (pl.moving_down && pl.moving_up && pl.moving_rigth)
		dir = ft_rotate_vector(pl.dir, 90, true);
	else if (pl.moving_down && pl.moving_up)
		dir = (t_dvector){0, 0};
	else if (pl.moving_down && pl.moving_left)
		dir = ft_rotate_vector(pl.dir, 135, false);
	else if (pl.moving_down && pl.moving_rigth)
		dir = ft_rotate_vector(pl.dir, 135, true);
	else if (pl.moving_up && pl.moving_left)
		dir = ft_rotate_vector(pl.dir, 45, false);
	else if (pl.moving_rigth && pl.moving_up)
		dir = ft_rotate_vector(pl.dir, 45, true);
	else if (pl.moving_left && pl.moving_rigth)
		dir = (t_dvector){0, 0};
	else if (pl.moving_down)
		dir = ft_rotate_vector(pl.dir, 180, true);
	else if (pl.moving_up)
		dir = pl.dir;
	else if (pl.moving_left)
		dir = ft_rotate_vector(pl.dir, 90, false);
	else if (pl.moving_rigth)
		dir = ft_rotate_vector(pl.dir, 90, true);
	else
		dir = (t_dvector){0, 0};
	return (dir);
}

void	ft_move(t_program *p)
{
	t_dvector	mov_dir;
	t_dvector	new_position;

	mov_dir = ft_set_new_dir(p);
	new_position.x = p->player.pos.x + mov_dir.x * (double)MOVESPEED;
	new_position.y = p->player.pos.y + mov_dir.y * (double)MOVESPEED;
	if (p->map[(int)new_position.y][(int)new_position.x] == '1' || \
	p->map[(int)new_position.y][(int)new_position.x] == 'D')
		return ;
	p->player.pos.x = new_position.x;
	p->player.pos.y = new_position.y;

}

int	ft_update(void *p)
{
	static long long int	i;
	t_program				*program;
	time_t					start;
	time_t					end;

	program = p;

	program->frame = i;
	start = ft_return_time();
	ft_mouse_visual(program, i++);
	if (program->player.moving)
		ft_move(program);
	ft_ray_casting(program);
	end = ft_return_time();
	ft_fps(program, start, end);
	return (0);
}

//1 : diff(ms) = tot : 1000(ms)
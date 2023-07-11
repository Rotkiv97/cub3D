/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:56:49 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player_direction(t_program *p, char player)
{
	if (player == 'N')
	{
		p->player.dir = (t_dvector){0, -1};
		p->player.cam_plane = (t_dvector){(double)FOV, 0};
	}
	else if (player == 'S')
	{
		p->player.dir = (t_dvector){0, 1};
		p->player.cam_plane = (t_dvector){(double)(-FOV), 0};
	}
	else if (player == 'E')
	{
		p->player.dir = (t_dvector){1, 0};
		p->player.cam_plane = (t_dvector){0, FOV};
	}
	else if (player == 'W')
	{
		p->player.dir = (t_dvector){-1, 0};
		p->player.cam_plane = (t_dvector){0, -FOV};
	}
}

void	ft_player_position(t_program *p)
{
	int		i;
	char	player;

	i = 0;
	while (p->map[i])
	{
		if (ft_strchr_set(p->map[i], "NSWE"))
		{
			p->player.pos = (t_dvector) \
			{ft_strchr_set(p->map[i], "NSWE") - p->map[i] + 0.5, i + 0.5};
			break ;
		}
		i++;
	}
	player = *ft_strchr_set(p->map[i], "NSWE");
	ft_player_direction(p, player);
}

void	ft_player_init(t_program *p)
{
	p->player.interact = false;
	p->player.moving_up = false;
	p->player.moving_down = false;
	p->player.moving_left = false;
	p->player.moving_rigth = false;
	p->player.easter_egg = false;
	p->player.moving = false;
	p->player.rotating_left = false;
	p->player.rotating_rigth = false;
	ft_player_position(p);
}

void	ft_check_av(char *s)
{
	char	*trim;

	trim = ft_strtrim(s, " \t");
	if (ft_strlen(trim) <= 4)
	{
		ft_putstrerr("Invalid argument: string too short");
		free(trim);
		exit(3);
	}
	if (ft_strncmp(".cub", &trim[ft_strlen(trim) - 4], 5))
	{
		ft_putstrerr("Invalid argument: map files must end with .cub");
		free(trim);
		exit(4);
	}
	free(trim);
}

int	main(int ac, char **av)
{
	t_program		p;

	if (ac == 2)
	{
		ft_check_av(av[1]);
		ft_program_init(&p, av[1]);
		ft_player_init(&p);
		mlx_do_key_autorepeatoff(p.mlx);
		mlx_hook(p.window, 2, 1L << 0, ft_input, &p);
		mlx_hook(p.window, 3, 1L << 1, ft_input_release, &p);
		mlx_hook(p.window, 17, 0, ft_close, &p);
		mlx_loop_hook(p.mlx, ft_update, &p);
		mlx_loop(p.mlx);
	}
}

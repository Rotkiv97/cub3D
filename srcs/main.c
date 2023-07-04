/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 17:07:29 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player_init(t_program *p, t_player *pl)
{
	char	**map;
	int		i;

	i = 0;
	map = (p->map);
	pl->dir = (t_dvector){0, -1};
	pl->cam_plane = (t_dvector){FOV, 0};
	while (map[i])
	{
		if (ft_strchr(map[i], 'N'))
		{
			pl->pos = (t_dvector){ft_strchr(map[i], 'N') - map[i] + 0.5 , i + 0.5};
			//ft_print_vector(&(pl->pos), true);
			break ;
		}
		i++;
	}
}

void	ft_img_init(t_program *p, t_img *screen)
{
	screen->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel, \
	&screen->line_length, &screen->endian);
}

void	ft_program_init(t_program *p, t_player *pl, t_img *screen, char *file_path)
{
	ft_map_checker(p, file_path);
	ft_player_init(p, pl);
	p->fov = FOV;
	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "cub3D");
	p->pause = 0;
	ft_read_file(p);
	mlx_mouse_get_pos(p->mlx, p->window, &p->mouse.x, &p->mouse.y);
	ft_img_init(p, screen);
	p->player = *pl;
	p->screen = *screen;
}

int	ft_mouse(int x, int y, t_program *p)
{
	(void)p;
	printf("%d\n", x);
	printf("%d\n", y);

	//ft_ray_casting(p);
	return (0);
}

int	main(int ac, char **av)
{
	t_program		p;
	t_player		pl;
	t_img			screen;

	if (ac == 2)
	{
		ft_program_init(&p, &pl, &screen, av[1]);
		mlx_hook(p.window, 2, 1L << 0, *ft_input, &p);
		mlx_hook(p.window, 17, 0, ft_close, &p);
		mlx_loop_hook(p.mlx, ft_update, &p);
		mlx_loop(p.mlx);
	}
}

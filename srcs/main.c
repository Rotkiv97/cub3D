/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/27 15:03:50 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player_init(t_player *pl)
{
	pl->dir = (t_float_vector){0, -1};
	pl->pos = (t_float_vector){2.5, 3.7};	//fill with N position in the maps
	pl->n_rays = RAYS;
}

void	ft_img_init(t_program *p, t_img *screen)
{
	screen->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel, \
	&screen->line_length, &screen->endian);
	printf("bit per pixel : %d\n", screen->bits_per_pixel);
	printf("line length : %d\n", screen->line_length);
	printf("endian : %d\n", screen->endian);
}

void	ft_program_init(t_program *p, t_player *pl, t_img *screen, char *file_path)
{
	ft_map_checker(p, file_path);
	p->map = (char **) malloc (sizeof(char *) * 6);
	p->map[0] = ft_strdup("111111");
	p->map[1] = ft_strdup("110101");
	p->map[2] = ft_strdup("100001");
	p->map[3] = ft_strdup("100N01");
	p->map[4] = ft_strdup("111111");
	p->map[5] = 0;
	p->fov = FOV;
	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "cub3D");
	ft_img_init(p, screen);
	ft_player_init(pl);
	p->player = *pl;
}

int	main(int ac, char **av)
{
	t_program		p;
	t_player		pl;
	t_img			screen;
	//double			ray_angle;

	if (ac == 2)
	{
		ft_program_init(&p, &pl, &screen, av[1]);
		/* for (int i = 0; i < 100; i++)
		{
			ft_ray_casting(&p);
			ray_angle = (20 * PI) / 180;
			usleep(500000);
			p.player.dir.x = cos(ray_angle) * p.player.dir.x - sin(ray_angle) * p.player.dir.y;
			p.player.dir.y = sin(ray_angle) * p.player.dir.x + cos(ray_angle) * p.player.dir.y;
			mlx_clear_window(p.mlx, p.window);
		}
		mlx_loop(p.mlx); */
	}
}

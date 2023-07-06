/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/06 16:30:25 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player_init(t_program *p)
{
	char	**map;
	int		i;

	i = 0;
	map = (p->map);
	p->player.dir = (t_dvector){0, -1};
	p->player.cam_plane = (t_dvector){(double)FOV, 0};
	p->player.moving_up = false;
	p->player.moving_down = false;
	p->player.moving_left = false;
	p->player.moving_rigth = false;
	p->player.moving = false;
	while (map[i])
	{
		if (ft_strchr(map[i], 'N'))
		{
			p->player.pos = (t_dvector){ft_strchr(map[i], 'N') - map[i] \
			+ 0.5, i + 0.5};
			break ;
		}
		i++;
	}
}

void	ft_img_init(t_program *p)
{
	int		i;
	char	*animations;
	char	*itoa;

	p->screen.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->screen.addr = mlx_get_data_addr(p->screen.img, \
	&p->screen.bits_per_pixel, &p->screen.line_length, &p->screen.endian);
	p->sprites.ceiling.img = 0;
	p->sprites.floor.img = 0;
	p->sprites.north.img = 0;
	p->sprites.south.img = 0;
	p->sprites.west.img = 0;
	p->sprites.east.img = 0;
	p->sprites.door.img = 0;
	p->ceil_color = 0;
	p->floor_color = 0;
	i = 0;
	while (i < 9)
	{
		itoa = ft_itoa(i + 1); 
		animations = ft_strjoin(itoa , ".xpm");
		animations = ft_strjoin("./textures/animation_test/", animations);
		p->sprites.animations[i].img = \
		mlx_xpm_file_to_image(p->mlx, animations, \
		&p->sprites.animations[i].width, &p->sprites.animations[i].height);
		mlx_get_data_addr(p->sprites.animations[i].img, &p->sprites.animations[i].bits_per_pixel, &p->sprites.animations[i].line_length, &p->sprites.animations[i].endian);
		printf("ok\n");
		free(itoa);
		i++;
	}
}

void	ft_program_init(t_program *p, char *file_path)
{
	ft_map_checker(p, file_path);
	p->mlx = mlx_init();
	if (!p->mlx)
		exit(-1);	//meglio
	ft_img_init(p);
	ft_read_file(p);
	p->pause = 0;
	p->frame = 0;
	p->fov = FOV;
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "cub3D");
	ft_player_init(p);
	mlx_mouse_get_pos(p->mlx, p->window, &p->mouse.x, &p->mouse.y);
}

int	main(int ac, char **av)
{
	t_program		p;

	if (ac == 2)
	{
		ft_program_init(&p, av[1]);
		mlx_hook(p.window, 2, 1L << 0, ft_input, &p);
		mlx_hook(p.window, 3, 1L << 1, ft_input_release, &p);
		mlx_hook(p.window, 17, 0, ft_close, &p);
		mlx_loop_hook(p.mlx, ft_update, &p);
		mlx_loop(p.mlx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/09 20:55:49 by dcolucci         ###   ########.fr       */
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
	p->player.interact = false;
	p->player.moving_up = false;
	p->player.moving_down = false;
	p->player.moving_left = false;
	p->player.moving_rigth = false;
	p->player.easter_egg = false;
	p->player.moving = false;
	p->player.rotating_left = false;
	p->player.rotating_rigth = false;
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

void	ft_load_animations(t_program *p, char *path, int n_animations, t_img *animations)
{
	int		i;
	char	*full_path;
	char	*itoa;
	char	*tmp;

	i = 0;
	while (i < n_animations)
	{
		itoa = ft_itoa(i + 1); 
		tmp = ft_strjoin(itoa , ".xpm");
		full_path = ft_strjoin(path, tmp);
		animations[i].img = \
		mlx_xpm_file_to_image(p->mlx, full_path, \
		&animations[i].width, &animations[i].height);
		free(itoa);
		free(tmp);
		if (!animations[i].img)
		{
			printf("%s", full_path);
			free(full_path);
			ft_exit(" : animation not found!");
		}
		free(full_path);
		animations[i].addr = mlx_get_data_addr(animations[i].img,\
		&animations[i].bits_per_pixel, &animations[i].line_length, \
		&animations[i].endian);
		i++;
	}
}

void	ft_animation_init(t_program *p)
{
	ft_load_animations(p, "./textures/animation_test/left_arm/", 4, p->sprites.interact);
	ft_load_animations(p, "./textures/animation_test/lantern/", 9, p->sprites.animations);
	ft_load_animations(p, "./textures/animation_test/easter_egg/", 4, p->sprites.easter_egg);
	ft_load_animations(p, "./textures/minimap/", 8, p->sprites.arrow);
	ft_load_animations(p, "./textures/maze/portal/", 8, p->sprites.portal);
	p->sprites.guide.img = mlx_xpm_file_to_image(p->mlx, "./textures/maze/door_closed.xpm", \
	&p->sprites.guide.width, &p->sprites.guide.height);
	p->sprites.guide.addr = mlx_get_data_addr(p->sprites.guide.img, &p->sprites.guide.bits_per_pixel, \
	&p->sprites.guide.line_length, &p->sprites.guide.endian);
}

void	ft_img_init(t_program *p)
{
	p->screen.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->screen.addr = mlx_get_data_addr(p->screen.img, \
	&p->screen.bits_per_pixel, &p->screen.line_length, &p->screen.endian);
	if (!p->screen.img)
		ft_exit("Cannot open window");
	ft_animation_init(p);
	p->sprites.north.img = 0;
	p->sprites.south.img = 0;
	p->sprites.west.img = 0;
	p->sprites.east.img = 0;
	p->sprites.door.img = 0;
	p->ceil_color = 0;
	p->floor_color = 0;
	
}

void	ft_program_init(t_program *p, char *file_path)
{
	ft_map_checker(p, file_path);
	p->mlx = mlx_init();
	if (!p->mlx)
		exit(-1);	//meglio
	ft_img_init(p);
	ft_read_file(p);
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "cub3D");
	ft_player_init(p);
	mlx_mouse_get_pos(p->mlx, p->window, &p->mouse.x, &p->mouse.y);
	p->pause = 0;
	p->frame = 0;
	p->fov = FOV;
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

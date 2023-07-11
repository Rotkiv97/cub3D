/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:05:51 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:02:03 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	ft_open_xpm(t_program *p, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(p->mlx, path, &img.width, &img.height);
	if (img.img)
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	return (img);
}

void	ft_load_animations(t_program *p, char *path, int n_animations, \
t_img *animations)
{
	int		i;
	char	*full_path;
	char	*itoa;
	char	*tmp;

	i = 0;
	while (i < n_animations)
	{
		itoa = ft_itoa(i + 1);
		tmp = ft_strjoin(itoa, ".xpm");
		full_path = ft_strjoin(path, tmp);
		animations[i] = ft_open_xpm(p, full_path);
		free(itoa);
		free(tmp);
		free(full_path);
		if (!animations[i].img)
			ft_exit(" : animation not found!", p);
		i++;
	}
}

void	ft_animation_init(t_program *p)
{
	ft_load_animations(p, "./textures/animations/left_arm/", \
	4, p->sprites.interact);
	ft_load_animations(p, "./textures/animations/lantern/", \
	9, p->sprites.animations);
	ft_load_animations(p, "./textures/animations/easter_egg/", \
	4, p->sprites.easter_egg);
	ft_load_animations(p, "./textures/minimap/", 8, p->sprites.arrow);
	ft_load_animations(p, "./textures/maze/portal/", 8, p->sprites.portal);
	p->sprites.current_portal = 0;
	p->sprites.door = ft_open_xpm(p, "./textures/maze/door.xpm");
	p->sprites.guide = ft_open_xpm(p, "./textures/maze/guide.xpm");
	p->sprites.home = ft_open_xpm(p, "./textures/maze/home.xpm");
}

void	ft_img_init(t_program *p)
{
	p->screen.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->screen.addr = mlx_get_data_addr(p->screen.img, \
	&p->screen.bits_per_pixel, &p->screen.line_length, &p->screen.endian);
	if (!p->screen.img)
		ft_exit("Cannot open window", p);
	ft_animation_init(p);
	p->sprites.north.img = 0;
	p->sprites.south.img = 0;
	p->sprites.west.img = 0;
	p->sprites.east.img = 0;
	p->ceil_color = 0;
	p->floor_color = 0;
}

void	ft_program_init(t_program *p, char *file_path)
{
	ft_map_checker(p, file_path);
	p->mlx = mlx_init();
	if (!p->mlx)
		ft_exit("Error \nCannot init program", p);
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_mouse_get_pos(p->mlx, p->window, &p->mouse.x, &p->mouse.y);
	p->sprites.easter_done = false;
	p->pause = 0;
	p->frame = 0;
	p->fov = FOV;
	ft_img_init(p);
	ft_read_file(p);
}

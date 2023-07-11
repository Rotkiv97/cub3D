/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:10:03 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:42:06 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_mat(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return ;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void	ft_exit(char *error, t_program *p)
{
	printf("\033[31m%s\033[0m\n", error);
	if (p->map)
		ft_free_mat(p->map);
	if (p->file)
		ft_free_mat(p->file);
	exit(0);
}

void	ft_destroy_animations(t_program *p, int n, t_img *animation)
{
	int	i;

	i = 0;
	if (!animation)
		return ;
	while (i < n)
	{
		if (animation[i].img)
			mlx_destroy_image(p->mlx, animation[i].img);
		i++;
	}
}

void	ft_destroy_sprites(t_program *p)
{
	ft_destroy_animations(p, 1, &p->sprites.east);
	ft_destroy_animations(p, 1, &p->sprites.south);
	ft_destroy_animations(p, 1, &p->sprites.north);
	ft_destroy_animations(p, 1, &p->sprites.west);
	ft_destroy_animations(p, 9, p->sprites.animations);
	ft_destroy_animations(p, 4, p->sprites.interact);
	ft_destroy_animations(p, 4, p->sprites.easter_egg);
	ft_destroy_animations(p, 8, p->sprites.arrow);
	ft_destroy_animations(p, 8, p->sprites.portal);
	ft_destroy_animations(p, 1, &p->sprites.guide);
	ft_destroy_animations(p, 1, &p->sprites.home);
	ft_destroy_animations(p, 1, &p->sprites.door);
}

void	ft_free_program(t_program *p)
{
	mlx_clear_window(p->mlx, p->window);
	mlx_destroy_window(p->mlx, p->window);
	ft_free_mat(p->map);
	ft_free_mat(p->file);
	mlx_destroy_image(p->mlx, p->screen.img);
	ft_destroy_sprites(p);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:10:03 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/09 20:56:08 by dcolucci         ###   ########.fr       */
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

void	ft_free_exit(char *error, char *str)
{
	printf("\033[31m%s\033[0m\n", error);
	free(str);
	exit(0);
}

void	ft_exit(char *error)
{
	printf("\033[31m%s\033[0m\n", error);
	exit(0);
}

void	ft_destroy_sprites(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprites.door.img);
	mlx_destroy_image(p->mlx, p->sprites.east.img);
	mlx_destroy_image(p->mlx, p->sprites.north.img);
	mlx_destroy_image(p->mlx, p->sprites.south.img);
	mlx_destroy_image(p->mlx, p->sprites.west.img);
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

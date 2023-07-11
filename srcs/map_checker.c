/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:47 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:17:13 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_map_last_00(t_program *p, char **map, int y, int size)
{
	char	*chars;
	int		x;

	x = 0;
	chars = "NP0DULSWE";
	while (map[y][x])
	{
		if (y != 0 || y != size - 1)
			if (ft_in_set(map[y][x], chars))
				ft_check_map_last_01(p, map, x, y);
		x++;
	}
}

void	ft_check_map_last_02(t_program *p, char **map, int size, int x)
{
	int		y;
	char	*str;

	str = " 1\n";
	y = -1;
	while (map[++y])
	{
		x = 0;
		if (&map[y] != &map[size - 1])
			ft_check_map_last_00(p, map, y, size);
		else if (&map[y] == &map[size - 1])
		{
			while (map[size - 1][x])
			{
				if (!ft_in_set(map[size - 1][x], str))
					ft_exit("errore nella ultima stringa", p);
				x++;
			}
		}
	}
}

void	ft_check_map_last(char **map, t_program *p)
{
	int		x;
	char	*str;
	int		size;

	str = " 1\n";
	x = -1;
	size = 0;
	while (map[size])
		size++;
	while (map[0][++x])
		if (!ft_in_set(map[0][x], str))
			ft_exit("errore nella prima stringa", p);
	ft_check_map_last_02(p, map, size, x);
}

void	ft_map_checker(t_program *p, char *file_path)
{
	p->file = 0;
	p->map = 0;
	p->file = ft_copy_file(file_path);
	if (!(p->file))
	{
		ft_putstrerr("Error\nCannot open file :");
		ft_putstrerr(file_path);
		exit(2);
	}
	ft_check_map_file(p);
	ft_check_char(p);
	ft_check_walls(p);
	ft_check_map_last(p->map, p);
}

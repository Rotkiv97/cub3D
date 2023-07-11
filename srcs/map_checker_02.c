/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:14:49 by vguidoni          #+#    #+#             */
/*   Updated: 2023/07/11 17:14:05 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* controlliamo i caratteri */

void	ft_flag(int flag, t_program *p)
{
	if (flag == 0)
		ft_exit("No player position", p);
	else if (flag > 1)
		ft_exit("Too many player spawn points", p);
}

void	ft_check_char(t_program *p)
{
	int		x;
	int		y;
	char	*chars;
	int		flag;

	y = -1;
	chars = "10 NSWEDLPU\n";
	flag = 0;
	while (p->map[++y] != NULL)
	{
		x = 0;
		while (p->map[y][x] != '\0')
		{
			if (ft_in_set(p->map[y][x], chars))
			{
				if (ft_in_set(p->map[y][x], "NSEW") == 1)
					flag += 1;
				x++;
			}
			else
				ft_exit("Invalid chars", p);
		}
	}
	ft_flag(flag, p);
}

/* controllo del primo e ultimo carattere della mappa che sia 1*/
void	ft_check_walls(t_program *p)
{
	int		y;
	char	*tmp;

	y = 0; 
	while (p->map[y])
	{
		tmp = ft_strtrim(p->map[y], " \t\n");
		if (tmp[0] != '1')
		{
			free(tmp);
			ft_exit("Invalid lateral edges", p);
		}
		else if (tmp[ft_strlen(tmp) - 1] != '1')
		{
			free(tmp);
			ft_exit("Invalid lateral edges", p);
		}
		free(tmp);
		y++;
	}
}

/*  da qui in poi si faranno tutti i 
controlli della mappa e dei suoi caratteri */

void	ft_check_map_last_01(t_program *p, char **map, int x, int y)
{
	if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		ft_exit("Invalid inner edges", p);
	else if (map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
		ft_exit("Invalid inner edges", p);
	else if (!map[y - 1][x] && ft_strlen(map[y - 1]) < ft_strlen(map[y]))
		ft_exit("Invalid inner edges", p);
	else if (map[y + 1][x] == ' ')
		ft_exit("Invalid inner edges", p);
	else if (map[y + 1][x] == '\n')
		ft_exit("Invalid inner edges", p);
	else if (!map[y + 1][x] && ft_strlen(map[y]) > ft_strlen(map[y + 1]))
		ft_exit("Invalid inner edges", p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:14:49 by vguidoni          #+#    #+#             */
/*   Updated: 2023/07/11 12:14:52 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* controlliamo i caratteri */

void	ft_flag(int flag)
{
	if (flag == 0)
		ft_exit("sei un troglodita metti il punto o di inizio");
	else if (flag > 1)
		ft_exit("allora non ci intendiamo metti solo 1 span, e impiccati");
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
				ft_exit("cogline Metti i caratteri giusti");
		}
	}
	ft_flag(flag);
}

/* controllo del primo e ultimo carattere della mappa che sia 1*/
void	ft_check_walls(char **map)
{
	int		y;
	char	*tmp;

	y = 0; 
	while (map[y])
	{
		tmp = ft_strtrim(map[y], " \t\n");
		if (tmp[0] != '1')
			ft_free_exit("invalid map asse y sinistra", tmp);
		else if (tmp[ft_strlen(tmp) - 1] != '1')
			ft_free_exit("invalid map asse y defatra", tmp);
		free(tmp);
		y++;
	}
}

/*  da qui in poi si faranno tutti i 
controlli della mappa e dei suoi caratteri */



void	ft_check_map_last_01(char **map, int x, int y)
{
	if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		ft_exit("invalid map bordi chars");
	else if (map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
		ft_exit("invalid map bordi superiori chars");
	else if (!map[y - 1][x] && ft_strlen(map[y - 1]) < ft_strlen(map[y]))
		ft_exit("invalid map bordi superiori chars");
	else if (map[y + 1][x] == ' ')
		ft_exit("invalid map bordi inferiori chars");
	else if (map[y + 1][x] == '\n')
		ft_exit("invalid map bordi inferiori chars");
	else if (!map[y + 1][x] && ft_strlen(map[y]) > ft_strlen(map[y + 1]))
		ft_exit("invalid map bordi inferiori chars");
}

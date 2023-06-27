/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:47 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 18:23:33 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	**ft_copy_map(char *map_path)
{
	char	**file;
	int		lines;
	int		fd;
	char	c;

	lines = 1;
	fd = open (map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			lines++;
	close(fd);
	file = (char **) malloc (sizeof(char *) * (lines + 1));
	lines = 0;
	fd = open(map_path, O_RDONLY);
	file[lines] = get_next_line(fd);
	while (file[lines++])
		file[lines] = get_next_line(fd);
	close (fd);
	return (file);
}

/*qui andiamo a distinguere il file dalla mappa, di conseguenza 
ci salveremo all'interno di p->map solo la mappa*/

void	ft_check_map_file(t_program *p)
{
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (p->file[y])
	{
		if (p->file[y][0] == ' ' || p->file[y][0] == '1')
		{
			while (ft_strncmp(p->file[y + k], "\n", 2) && p->file[y + k] != 0)
				k++;
			break ;
		}
		y++;
	}
	p->map = (char **)malloc(sizeof(char *) * (k + 1));
	k = 0;
	while (p->file[y + k] && ft_strncmp(p->file[y + k], "\n", 2) \
	&& p->file[y + k] != 0)
	{
		p->map[k] = ft_strdup(p->file[y + k]);
		k++;
	}
	p->map[k] = 0;
}



/* controlliamo i caratteri */

void	ft_check_char(t_program *p)
{
	int		x;
	int		y;
	char	*chars;

	y = -1;
	chars = "10 NPE\n";
	p->N_flag = 0;
	while (p->map[++y] != NULL)
	{
		x = 0;
		while (p->map[y][x] != '\0')
		{
			if (ft_in_set(p->map[y][x], chars))
			{
				if (ft_in_set(p->map[y][x], "N") == 1)
					p->N_flag += 1;
				x++;
			}
			else
				ft_exit("cogline Metti i caratteri giusti");
		}
	}
	if (p->N_flag == 0)
		ft_exit("sei un troglodita metti il punto o di inizio");
	else if (p->N_flag > 1)
		ft_exit("allora non ci intendiamo metti solo 1 span, e impiccati");
}

/* controllo del primo e ultimo carattere della mappa che sia 1*/

void	ft_check_walls(char **map)
{
	int		y;
	char	**tmp;

	y = 0;
	while (map[y])
		y++;
	tmp = (char **)malloc(sizeof(char *) * (y + 1));
	y = 0; 
	while (map[y])
	{
		tmp[y] = ft_strtrim(map[y], " \n");
		if (tmp[y][0] != '1')
			ft_free_exit("invalid map asse y sinistra", tmp);
		else if (tmp[y][ft_strlen(tmp[y]) - 1] != '1')
			ft_free_exit("invalid map asse y defatra", tmp);
		y++;
	}
	free(tmp);
}

/* da qui in poi si faranno tutti i 
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
	else
		x++;
}

void	ft_check_map_last_00(char **map, int y, int x, int size)
{
	char	*chars;

	chars = "NP0";
	while (map[y][x])
	{
		if (y != 0 || y != size - 1)
			if (ft_in_set(map[y][x], chars))
				ft_check_map_last_01(map, x, y);
		x++;
	}
}

void	ft_check_map_last(char **map)
{
	int		x;
	int		y;
	char	*str;
	int		size;

	x = 0;
	str = " 1\n";

	size = 0;
	while (map[size])
		size++;
	while (map[0][x])
	{
		if (!ft_in_set(map[0][x], str))
			ft_exit("errore nella prima stringa");
		x++;
	}
	y = -1;
	while (map[++y])
	{
		x = 0;
		if (!map[size - 1])
			ft_check_map_last_00(map, y, x, size);
		else if (map[size - 1])
		{
			while (map[size - 1][x])
			{
				if (!ft_in_set(map[size - 1][x], str))
					ft_exit("errore nella ultima stringa");
				x++;
			}
		}
	}
}

void	ft_map_checker(t_program *p, char *map_path)
{
	p->file = ft_copy_map(map_path);
	if (!(p->file))
	{
		ft_putstrerr("Cannot open map");
		exit(2);
	}
	ft_check_map_file(p);
	ft_check_char(p);
	ft_check_walls(p->map);
	ft_check_map_last(p->map);
	ft_print_mat(p->map, false);
}

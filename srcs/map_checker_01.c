/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:46:26 by vguidoni          #+#    #+#             */
/*   Updated: 2023/07/11 11:46:29 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**ft_copy_file(char *file_path)
{
	char	**file;
	int		lines;
	int		fd;
	char	c;

	lines = 1;
	fd = open (file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			lines++;
	close(fd);
	file = (char **) malloc (sizeof(char *) * (lines + 1));
	lines = 0;
	fd = open(file_path, O_RDONLY);
	file[lines] = get_next_line(fd);
	while (file[lines++])
		file[lines] = get_next_line(fd);
	close (fd);
	return (file);
}

void	ft_checker_map_01(t_program *p, int y, int k)
{
	while (p->file[y + k] && ft_strncmp(p->file[y + k], "\n", 2) \
	&& p->file[y + k] != 0)
	{
		p->map[k] = ft_strtrim(p->file[y + k], "\t");
		k++;
	}
	p->map[k] = 0;
	while (p->file[y + k])
	{
		if (ft_strncmp(p->file[y + k], "\n", 2))
			ft_exit("troclodita la mappa e' l'ultimo argomento");
		y++;
	}
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
		if (p->file[y][0] == ' ' || \
		p->file[y][0] == '1' || p->file[y][0] == '\t')
		{
			while (p->file[y + k] != 0 && ft_strncmp(p->file[y + k], "\n", 2))
				k++;
			break ;
		}
		y++;
	}
	p->map = (char **)malloc(sizeof(char *) * (k + 1));
	k = 0;
	ft_checker_map_01(p, y , k);
}

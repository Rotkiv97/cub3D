/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:47 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/23 19:14:59 by dcolucci         ###   ########.fr       */
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

void	ft_map_checker(t_program *p, char *file_path)
{
	p->map = ft_copy_file(file_path);
	if (!(p->map))
	{
		ft_putstrerr("Cannot open map");
		exit(2);
	}
	/* ft_check_char(p->map);
	ft_check_walls(p->map);
	ft_check_map_last(p->map); */
}

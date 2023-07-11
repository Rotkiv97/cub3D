/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:52 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:12:59 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_open_texture(t_program *p, char *texture, char c)
{
	char	*trim;
	t_img	img;

	trim = ft_strtrim(texture, " \t\n");
	if (!trim)
		return ;
	img.img = mlx_xpm_file_to_image(p->mlx, trim, &img.width, &img.height);
	free(trim);
	if (!img.img)
	{
		ft_free_program(p);
		ft_putstrerr("Invalid Texture!");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	if (c == 'N')
		p->sprites.north = img;
	else if (c == 'S')
		p->sprites.south = img;
	else if (c == 'E')
		p->sprites.east = img;
	else if (c == 'W')
		p->sprites.west = img;
}

void	ft_set_color(t_program *p, char *line_color)
{
	char			**split;
	int				y;
	unsigned int	color;

	y = 0;
	if (!line_color)
		return ;
	split = ft_split(line_color, ',');
	while (split[y])
	{
		color = color << 8;
		if (ft_atoi(split[y]) <= 255)
			color = color | ft_atoi(split[y]);
		y++;
	}
	if (line_color[0] == 'C')
		p->ceil_color = color;
	else
		p->floor_color = color;
	ft_free_mat(split);
}

void	ft_read_color(t_program *p)
{
	char			*tmp;
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (p->file[x])
	{
		y = 0;
		tmp = ft_strtrim(p->file[x], " \t\n");
		if (!tmp)
			return ;
		if (tmp[0] == 'C' || tmp[0] == 'F')
		{
			while (ft_in_set(tmp[y], " \t"))
				y++;
			ft_set_color(p, &tmp[y]);
		}
		free(tmp);
		x++;
	}
}

void	ft_read_file(t_program *p)
{
	int		i;

	i = 0;
	ft_read_color(p);
	while (p->file[i])
	{
		if (ft_strnstr(p->file[i], "NO ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "NO ", 4) + 3, 'N');
		else if (ft_strnstr(p->file[i], "SO ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "SO ", 4) + 3, 'S');
		else if (ft_strnstr(p->file[i], "WE ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "WE ", 4) + 3, 'W');
		else if (ft_strnstr(p->file[i], "EA ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "EA ", 4) + 3, 'E');
		i++;
	}
}

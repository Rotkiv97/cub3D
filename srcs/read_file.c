/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:52 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/04 17:10:48 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_open_texture(t_program *p, char *texture, char c, bool needed)
{
	char	*trim;
	t_img	img;

	trim = ft_strtrim(texture, " \t\n");
	if (!trim)
		return ;
	img.img = mlx_xpm_file_to_image(p->mlx, trim, &img.width, &img.height);
	free(trim);
	if (!img.img && needed)
		ft_exit("Invalid texture");
	else if (!img.img && !needed)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (c == 'N')
		p->sprites.north = img;
	else if (c == 'S')
		p->sprites.south = img;
	else if (c == 'E')
		p->sprites.east = img;
	else if (c == 'W')
		p->sprites.west = img;
	else if (c == 'C')
		p->sprites.ceiling = img;
	else if (c == 'F')
		p->sprites.floor = img;
	else if (c == 'D')
		p->sprites.door = img;
}

void	ft_read_color(t_program *p)
{
	char			*tmp;
	char			**split;
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	color = 0;
	while (p->file[x])
	{
		y = 0;
		tmp = ft_strtrim(p->file[x], " \t\n");
		if (!tmp)
			return ;
		if (tmp[0] == 'C' || tmp[0] == 'F')
		{
			y++;
			while (ft_in_set(tmp[y], " \t"))
				y++;
			split = ft_split(&tmp[y], ',');
			y = 0;
			while (split[y])
			{
				color = color << 8;
				if (ft_atoi(split[y]) <= 255)
					color = color | ft_atoi(split[y]);
				y++;
			}
			if (tmp[0] == 'C')
				p->ceil_color = color;
			else
				p->floor_color = color;
			ft_free_mat(split);
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
			ft_open_texture(p, ft_strnstr(p->file[i], "NO ", 4) + 3, 'N', true);
		else if (ft_strnstr(p->file[i], "SO ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "SO ", 4) + 3, 'S', true);
		else if (ft_strnstr(p->file[i], "WE ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "WE ", 4) + 3, 'W', true);
		else if (ft_strnstr(p->file[i], "EA ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "EA ", 4) + 3, 'E', true);
		else if (ft_strnstr(p->file[i], "CT ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "CT ", 4) + 3, 'C', false);
		else if (ft_strnstr(p->file[i], "FT ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "FT ", 4) + 3, 'F', false);
		else if (ft_strnstr(p->file[i], "DO ", 4))
			ft_open_texture(p, ft_strnstr(p->file[i], "DO ", 4) + 3, 'D', false);
		i++;
	}
}
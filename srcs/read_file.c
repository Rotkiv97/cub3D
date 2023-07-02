/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:52 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/02 19:07:31 by dcolucci         ###   ########.fr       */
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
	if (!img.img)
		ft_exit("Invalid texture");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (c == 'N')
		p->textures[0] = img;
	else if (c == 'S')
		p->textures[1] = img;
	else if (c == 'E')
		p->textures[2] = img;
	else if (c == 'W')
		p->textures[3] = img;
	free(trim);
}

void	ft_read_file(t_program *p)
{
	int		i;

	i = 0;
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
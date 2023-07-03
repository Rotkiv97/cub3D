/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:52 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/03 18:51:22 by dcolucci         ###   ########.fr       */
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
	printf("trim %s and img pointer %p \n", trim, img.img);
	if (!img.img && needed)
		ft_exit("Invalid texture");
	else if (!img.img && !needed)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (c == 'N')
		p->textures[0] = img;
	else if (c == 'S')
		p->textures[1] = img;
	else if (c == 'E')
		p->textures[2] = img;
	else if (c == 'W')
		p->textures[3] = img;
	else if (c == 'C')
		p->textures[4] = img;
	else if (c == 'F')
		p->textures[5] = img;
	else if (c == 'D')
		p->textures[6] = img;
	free(trim);
}

void	ft_read_file(t_program *p)
{
	int		i;

	i = 0;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/26 18:27:53 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player_init(t_player *pl)
{
	pl->dir = (t_float_vector){0, -1};
	pl->pos = (t_float_vector){2, 3};	//fill with N position in the maps
	pl->n_rays = RAYS;
}

void	ft_program_init(t_program *p, t_player *pl, char *file_path)
{
	ft_map_checker(p, file_path);
	p->map = (char **) malloc (sizeof(char *) * 6);
	p->map[0] = ft_strdup("111111");
	p->map[1] = ft_strdup("111111");
	p->map[2] = ft_strdup("111111");
	p->map[3] = ft_strdup("10N011"); // position : (2, 3)
	p->map[4] = ft_strdup("111111");
	p->map[5] = 0;
	p->fov = FOV;
	ft_player_init(pl);
	p->player = *pl;
}

int	main(int ac, char **av)
{
	t_program	p;
	t_player	pl;

	if (ac == 2)
	{
		ft_program_init(&p, &pl, av[1]);
		ft_ray_casting(&p);
	}
}

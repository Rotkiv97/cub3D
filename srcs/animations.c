/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:30:10 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/09 18:53:48 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	ft_draw_lantern(t_program *p)
{
	static int				an;

	if (ft_check_movement(p))
	{
		if (p->frame % 3 == 0)
			ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[an++]);
		else
			ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[an]);
		if (an > 8)
			an = 0;
	}
	else
	{
		ft_fill_texture(p, (t_ivector){WIDTH / 2, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.animations[4]);
	}
}

void	ft_easter_egg(t_program *p)
{
	static int		easter_egg;

	if (p->player.easter_egg && easter_egg < 4)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.easter_egg[easter_egg++]);
	else if (p->player.easter_egg)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.easter_egg[3]);
	else
		easter_egg = 0;
	
}

void	ft_draw_left(t_program *p)
{
	static int		interact;
	
	if (p->player.interact && interact < 4)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.interact[interact++]);
	else if (p->player.interact)
		ft_fill_texture(p, (t_ivector){0, HEIGHT / 2}, (t_ivector){WIDTH / 2, HEIGHT / 2}, p->sprites.interact[3]);
	else
		interact = 0;
}

void	ft_draw_animation(t_program *p)
{
	ft_draw_lantern(p);
	ft_easter_egg(p);
	if (!p->player.easter_egg)
		ft_draw_left(p);
}
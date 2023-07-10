/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:41:59 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/10 14:28:01 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_change_portal(t_program *p)
{
	t_dvector	new_position;
	static time_t		time;
	time_t				check;

	new_position.x = p->player.pos.x + p->player.dir.x;
	new_position.y = p->player.pos.y + p->player.dir.y;
	check = ft_return_time();
	if (p->map[(int)new_position.y][(int)new_position.x] == 'L' && (check - time) > 100)
	{
		p->sprites.current_portal = p->sprites.current_portal;
		p->sprites.current_portal++;
		if (p->sprites.current_portal == 8)
			p->sprites.current_portal = 0;
		time = ft_return_time();
	}
}
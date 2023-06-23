/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/23 19:42:28 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line_bonus.h"

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_vector
{
	int		x;
	int		y;
}t_int_vector;

typedef struct s_fvector
{
	float		x;
	float		y;
}t_float_vector;

typedef struct s_player
{
	t_float_vector	pos;
	t_float_vector	dir;
	int				cam_plane;
}t_player;

typedef struct s_program
{
	char			**map;
	int				cell_size;
	t_int_vector	map_size;
	t_player		player;
}t_program;

/*	map_checker.c	*/

void	ft_map_checker(t_program *p, char *file_path);

/*	project_path/srcs/utils/utils1.c	*/

void	ft_putstrerr(char *s);

/*	project_path/srcs/utils/utils_print.c	*/

void	ft_print_mat(char **mat, bool new_line);

/*	project_path/srcs/utils/utils_free.c	*/

void	ft_free_mat(char **mat);
void	ft_free_program(t_program *p);

#endif
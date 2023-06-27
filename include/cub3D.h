/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/27 15:36:39 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line_bonus.h"
# include "mlx.h"

# include <math.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PI 3.1415926535

# define FOV 180
# define RAYS 1000
# define HEIGHT	1080
# define WIDTH 1920

typedef struct s_vector
{
	int		x;
	int		y;
}t_int_vector;

typedef struct s_fvector
{
	float	x;
	float	y;
}t_float_vector;

typedef struct	s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_player
{
	t_float_vector	pos;
	t_float_vector	dir;
	int				n_rays;
}t_player;

typedef struct s_program
{
	void			*mlx;
	void			*window;
	t_img			screen;
	char			**map;
	char			**file;
	int				cell_size;
	float			fov;
	t_int_vector	map_size;
	t_player		player;
}t_program;

/*	project_path/map_checker.c	*/

void	ft_map_checker(t_program *p, char *file_path);

/*	project_path/srcs/ray_casting_dda.c	*/

void	ft_ray_casting(t_program *p);

/*	project_path/srcs/utils/utils1.c	*/

char	**ft_copy_mat(char **mat);
int	ft_in_set(char c, char *str);


/*	project_path/srcs/utils/utils_print.c	*/

void	ft_putstrerr(char *s);
void	ft_print_mat(char **mat, bool new_line);


/*	project_path/srcs/utils/utils_free.c	*/

void	ft_free_mat(char **mat);
void	ft_free_program(t_program *p);
void	ft_free_exit(char *error, char **str);
void	ft_exit(char *error);




#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/28 20:09:48 by dcolucci         ###   ########.fr       */
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

# define FOV 0.66
# define WIDTH 1280
# define HEIGHT	720
# define UNIT_HEIGHT (HEIGHT / 1.2)

# define MOVESPEED 0.2

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define NTEXT 0x33FF33
# define STEXT 0xFF8000
# define WTEXT 0x7F00FF
# define ETEXT 0xFF33FF

typedef struct s_vector
{
	int		x;
	int		y;
}t_ivector;

typedef struct s_fvector
{
	float	x;
	float	y;
}t_fvector;

typedef struct s_dvector
{
	double	x;
	double	y;
}t_dvector;


typedef struct	s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_player
{
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	cam_plane;
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
	t_ivector	map_size;
	t_player		player;
}t_program;

/*	draw_on_image.c	*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_black_screen(t_program *p);
void	ft_background(t_program *p);
void	ft_draw_vertical_line(t_program *p, double distance, int ray, t_dvector ray_dir);

/*	project_path/map_checker.c	*/

void	ft_map_checker(t_program *p, char *file_path);

/*	project_path/event/ft_update.c	*/

int		ft_update(void *program);

/*	project_path/event/key_hook.c	*/

int		ft_input(int key, void *program);

/*	project_path/srcs/ray_casting_dda.c	*/

void	ft_ray_casting(t_program *p);

/*	project_path/srcs/utils/utils_vector.c	*/

t_dvector	ft_rotate_vector(t_dvector vector, double angle, bool clockwise);
void			ft_rotate_visual(t_program *p, double angle, bool clockwise);

/*	project_path/srcs/utils/utils1.c	*/

char	**ft_copy_mat(char **mat);
int	ft_in_set(char c, char *str);


/*	project_path/srcs/utils/utils_print.c	*/

void	ft_putstrerr(char *s);
void	ft_print_vector(void *v, bool doubl);
void	ft_print_mat(char **mat, bool new_line);


/*	project_path/srcs/utils/utils_free.c	*/

void	ft_free_mat(char **mat);
void	ft_free_program(t_program *p);
void	ft_free_exit(char *error, char **str);
void	ft_exit(char *error);

#endif
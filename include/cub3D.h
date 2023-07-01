/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/01 19:39:12 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"

# include <math.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PI 3.1415926535

# define FOV 0.7
# define WIDTH 1920
# define HEIGHT	1080
# define UNIT_HEIGHT (HEIGHT / 1.2)

# define MOVESPEED 0.1
# define ROTSPEED 1.2

# define ESC 65307
# define PAUSE 112
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

# define FTEXT 0x112FA8
# define CTEXT 0x66FFFF

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
	int		width;
	int		height;
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
	char			**map;
	char			**file;
	int				cell_size;
	int				pause;
	double			fov;
	t_img			screen;
	t_img			textures[4];
	t_ivector		map_size;
	t_ivector		mouse;
	t_dvector		ray_dir;
	t_player		player;
}t_program;

/*	minimap.c	*/

void	ft_draw_minimap(t_program *p);

/*	draw_on_image.c	*/

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		ft_black_screen(t_program *p);
void		ft_background(t_program *p);
void		ft_draw_vertical_line(t_program *p, double distance, int pixel, int side_coll);

/*	project_path/map_checker.c	*/

void		ft_map_checker(t_program *p, char *file_path);

/*	project_path/event/ft_update.c	*/

int			ft_update(void *program);

/*	project_path/event/key_hook.c	*/

int			ft_input(int key, void *program);

/*	project_path/srcs/ray_casting_dda.c	*/

double		ft_distance_collision(t_program *p, t_dvector ray_dir, int *side_coll);
void		ft_ray_casting(t_program *p);

/*	srcs/read_file.c	*/

void		ft_read_file(t_program *p);

/*	project_path/srcs/utils/utils_vector.c	*/

t_dvector	ft_rotate_vector(t_dvector vector, double angle, bool clockwise);
void		ft_rotate_visual(t_program *p, double angle, bool clockwise);

/*	project_path/srcs/utils/utils1.c	*/

int			ft_mat_len(char **mat);
char		**ft_copy_mat(char **mat);
int			ft_in_set(char c, char *str);


/*	project_path/srcs/utils/utils_print.c	*/

void		ft_putstrerr(char *s);
void		ft_print_vector(void *v, bool doubl);
void		ft_print_mat(char **mat, bool new_line);


/*	project_path/srcs/utils/utils_free.c	*/

void		ft_free_mat(char **mat);
void		ft_free_program(t_program *p);
void		ft_free_exit(char *error, char **str);
void		ft_exit(char *error);

#endif
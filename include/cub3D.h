/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/10 19:15:47 by dcolucci         ###   ########.fr       */
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
# include <sys/time.h>

# define PI 3.1415926535

# define FOV 0.66
# define WIDTH 800
# define HEIGHT 600

# define MOVESPEED 0.15
# define ROTSPEED 1.5

# define ESC 65307
# define PAUSE 112
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define Q 113
# define LEFT 65361
# define RIGHT 65363

# define NTEXT 0x33FF33
# define STEXT 0xFF8000
# define WTEXT 0x7F00FF
# define ETEXT 0xFF33FF

# define FTEXT 0x112FA8
# define CTEXT 0x66FFFF

typedef struct s_ivector
{
	int		x;
	int		y;
}t_ivector;

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
	bool		easter_egg;
	bool		interact;
	bool		rotating_rigth;
	bool		rotating_left;
	bool		moving_up;
	bool		moving_down;
	bool		moving_left;
	bool		moving_rigth;
	bool		moving;
}t_player;

typedef struct s_sprites
{
	t_img	animations[9];
	t_img	interact[4];
	t_img	easter_egg[4];
	t_img	arrow[8];
	t_img	portal[8];
	int		current_portal;
	bool	easter_done;
	t_img	guide;
	t_img	home;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_img	door;
}t_sprites;

typedef struct s_rayinfo
{
	int			pixel;
	int			height;
	int			side;
	char		collision;
	double		real_distance;
	double		perp_distance;
	t_ivector	step;
	t_ivector	map_check;
	t_dvector	length1D;
	t_dvector	ray_dir;
	t_dvector	ray_start;
	t_dvector	scaling_factor;
}t_rayinfo;


typedef struct s_program
{
	void			*mlx;
	void			*window;
	char			**map;
	char			**file;
	long long int	frame;
	int				pause;
	double			fov;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	t_img			screen;
	t_sprites		sprites;
	t_rayinfo		ray;
	t_ivector		mouse;
	t_player		player;
}t_program;

/*	init.c	*/

void	ft_program_init(t_program *p, char *file_path);

/*	minimap.c	*/

void		ft_fill_cell_minimap(t_program *p, t_ivector position, t_ivector cell_size, int color);
void		ft_draw_minimap(t_program *p);

/*	draw_on_image.c	*/

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		my_mlx_pixel_put_transp(t_img *img, int x, int y, int color);
void		ft_draw_animation(t_program *p);
void		ft_fill_texture(t_program *p, t_ivector position, t_ivector size, t_img texture);
void		ft_black_screen(t_program *p);
void		ft_background(t_program *p, int pixel);
void		ft_draw_vertical_line(t_program *p, double distance, int pixel, int side_coll);

/*	texture.c	*/

void		ft_draw_texture(t_program *p, int pixel);

/*	project_path/map_checker.c	*/

void		ft_map_checker(t_program *p, char *file_path);

/*	project_path/event/ft_update.c	*/

long int	ft_return_time(void);
int			ft_update(void *program);

/*	project_path/event/key_hook.c	*/

bool		ft_check_movement(t_program *p);
void		ft_move(t_program *p);
void		ft_move_player(t_program *p, int key);
int			ft_input_release(int key, void *program);
int			ft_input(int key, void *program);

/*	srcs/event/easter_egg	*/

void		ft_change_portal(t_program *p);

/*	init_ray.c	*/

void		ft_init_ray(t_program *p, int pixel);

/*	project_path/srcs/ray_casting_dda.c	*/

unsigned int	ft_color_texture(t_program *p, t_img texture, t_ivector pixels, bool darker);
double			ft_distance_collision(t_program *p, t_dvector ray_dir);
void			ft_ray_casting(t_program *p);

/*	srcs/read_file.c	*/

void		ft_read_file(t_program *p);

/*	project_path/srcs/utils/utils_vector.c	*/

t_dvector	ft_rotate_vector(t_dvector vector, double angle, bool clockwise);
void		ft_rotate_visual(t_program *p, double angle, bool clockwise);

/*	project_path/srcs/utils/utils1.c	*/

int			ft_mat_len(char **mat);
char		**ft_copy_mat(char **mat);
char		*ft_strchr_set(char *str, char *set);
int			ft_in_set(char c, char *str);
int			ft_close(t_program *p);

/*	project_path/srcs/utils/utils_print.c	*/

void		ft_putstrerr(char *s);
void		ft_print_vector(void *v, bool doubl);
void		ft_print_mat(char **mat, bool new_line);
void		ft_fps(t_program *p, time_t start, time_t end);

/*	project_path/srcs/utils/utils_free.c	*/

void		ft_free_mat(char **mat);
void		ft_free_program(t_program *p);
void		ft_free_exit(char *error, char *str);
void		ft_exit(char *error);

#endif
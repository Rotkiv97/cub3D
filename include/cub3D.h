/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:48 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 18:31:52 by dcolucci         ###   ########.fr       */
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

typedef struct s_program
{
	char	**map;
}t_program;

/*	map_checker.c	*/

void	ft_map_checker(t_program *p, char *map_path);

/*	project_path/srcs/utils/utils1.c	*/

void	ft_putstrerr(char *s);

/*	project_path/srcs/utils/utils_print.c	*/

void	ft_print_mat(char **mat, bool new_line);

/*	project_path/srcs/utils/utils_free.c	*/

void	ft_free_mat(char **mat);
void	ft_free_program(t_program *p);

#endif
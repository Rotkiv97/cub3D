/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:50:00 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 16:18:05 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include<stdlib.h>
# include<unistd.h>

char	*ftgn_strdup(char *storage, char *to_free);
char	*ftgn_strjoin(char *storage, char *buf);
int		ftgn_strlen(char *str);
void	*ftgn_calloc(unsigned int nmemb, unsigned int size);
char	*get_next_line(int fd);
int		check_storage(char *storage);
char	*gurb_line(char *storage);
char	*update_storage(char *storage, int fd);
char	*clean_storage(char *storage);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:46:36 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 16:18:55 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	check_storage(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*grub_line(char *storage)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!storage)
		return (0);
	if (storage[i] == 0)
		return (0);
	while (storage[i] != '\n' && storage[i])
		i++;
	line = ftgn_calloc(sizeof(char) * (i + 2), sizeof(char));
	while (j <= i)
	{
		line[j] = storage[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_storage(char *storage, int fd)
{
	char	*tmpbuf;
	int		reading;

	if (!storage)
		return (0);
	reading = 1;
	while (!check_storage(storage) && reading > 0)
	{
		tmpbuf = ftgn_calloc(sizeof(char) * (BUFFER_SIZE + 1), sizeof(char));
		reading = read(fd, tmpbuf, BUFFER_SIZE);
		if (reading == -1)
		{
			free(tmpbuf);
			free(storage);
			return (0);
		}
		storage = ftgn_strjoin(storage, tmpbuf);
	}
	if (storage[0] == 0 && storage)
	{
		free(storage);
		return (0);
	}
	return (storage);
}

char	*clean_storage(char *storage)
{
	int		i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i])
		storage = ftgn_strdup(&storage[i + 1], storage);
	else
	{
		free(storage);
		storage = ftgn_calloc(1, 1);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(storage[fd]))
		storage[fd] = ftgn_calloc(1, sizeof(char));
	storage[fd] = update_storage(storage[fd], fd);
	line = grub_line(storage[fd]);
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
/*
int	main()
{
	char	*s;
	
	int	fd = open("file", O_RDONLY);
	s = get_next_line(fd);
	free(s);
}
*/

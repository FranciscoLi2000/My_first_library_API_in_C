/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylib <mylib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:00:00 by mylib             #+#    #+#             */
/*   Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);

/*
** Extracts line from buffer up to newline
** Returns line including \n, updates buffer with remainder
** Frees old buffer, returns NULL on malloc failure
*/

static char	*extract_line(char *buffer)
{
	char	*line;
	char	*newline_pos;
	size_t	len;
	size_t	i;

	newline_pos = gnl_strchr(buffer, '\n');
	if (newline_pos)
		len = newline_pos - buffer + 1;
	else
		len = gnl_strlen(buffer);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
** Updates buffer after extracting line
** Removes extracted line from buffer, keeps remainder
** Frees old buffer, returns new buffer or NULL
*/

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*newline_pos;
	size_t	i;

	newline_pos = gnl_strchr(buffer, '\n');
	if (!newline_pos)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (gnl_strlen(newline_pos + 1) + 1));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (newline_pos[1 + i])
	{
		new_buffer[i] = newline_pos[1 + i];
		i++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

/*
** Reads from fd into buffer until newline or EOF
** Appends read data to buffer using static variable
** Returns updated buffer or NULL on error
*/

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = gnl_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

/*
** Reads line from file descriptor
** Uses static buffer array for multi-fd support
** Returns line with \n if present, NULL on EOF/error
** Caller must free returned line
*/

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_to_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

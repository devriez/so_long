/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:03:41 by devriez           #+#    #+#             */
/*   Updated: 2025/06/05 14:43:38 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reduce_storage(char *storage, size_t full_line_len)
{
	char	*string;

	string = ft_substr(storage, full_line_len, \
										ft_strlen(storage) - full_line_len);
	free(storage);
	return (string);
}

static char	*strjoin(char *s1, char const *s2)
{
	char	*s_res;
	int		i;
	int		j;

	s_res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_res[i] = s1[i];
		i ++;
	}
	free(s1);
	j = 0;
	while (s2[j] != '\0')
	{
		s_res[i + j] = s2[j];
		j ++;
	}
	s_res [i + j] = '\0';
	return (s_res);
}

static char	*get_line_from_file(int fd, char *storage)
{
	ssize_t	read_bytes;
	char	*buf;

	read_bytes = BUFFER_SIZE;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	while (read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == 0)
			return (free(buf), storage);
		if (read_bytes < 0)
			return (free(storage), free(buf), NULL);
		buf[read_bytes] = '\0';
		storage = strjoin(storage, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), storage);
}

static char	*get_line_from_storage(char *storage, size_t *full_line_len)
{
	char	*next_line;
	size_t	line_len;
	size_t	i;

	if (!ft_strchr(storage, '\n'))
	{
		*full_line_len = ft_strlen(storage);
		return (ft_strdup(storage));
	}
	line_len = find_end_of_line(storage, full_line_len);
	next_line = (char *)malloc(sizeof(char) * (line_len + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		next_line[i] = storage[i];
		i++;
	}
	next_line[i] = '\n';
	next_line[i + 1] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*next_line;
	size_t		full_line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = get_line_from_file(fd, storage);
	if (!storage || storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	next_line = get_line_from_storage(storage, &full_line_len);
	if (!next_line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = reduce_storage(storage, full_line_len);
	return (next_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:04:13 by leolipes          #+#    #+#             */
/*   Updated: 2021/09/04 00:08:57 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_and_free(char *temp, char *buf_read, int aux)
{
	char	*line;

	line = ft_substr(temp, 0, aux + 1);
	free(temp);
	free(buf_read);
	return (line);
}

char	*join(int fd, char *buf_read, char *temp)
{
	char	*aux_temp;
	int		verification;

	verification = 1;
	while (verification)
	{
		verification = read (fd, buf_read, BUFFER_SIZE);
		if (verification <= 0 && temp[0] == 0)
		{
			free(temp);
			free(buf_read);
			return (NULL);
		}
		buf_read[verification] = '\0';
		aux_temp = temp;
		temp = ft_strjoin(temp, buf_read);
		if (!temp)
			return (NULL);
		free(aux_temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (temp);
}

char	*alloc_buf(void)
{
	char		*buf_read;

	buf_read = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_read)
	{
		free(buf_read);
		return (NULL);
	}
	return (buf_read);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf_read;
	char		*temp;
	size_t		aux;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	buf_read = alloc_buf();
	if (backup)
		temp = backup;
	else
		temp = ft_calloc(1, sizeof(char));
	temp = join(fd, buf_read, temp);
	if (!temp || !buf_read)
		return (NULL);
	aux = 0;
	while (temp[aux] != '\n' && temp[aux] != '\0')
		aux++;
	backup = ft_substr(temp, aux + 1, -1);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	return (alloc_and_free(temp, buf_read, aux));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:03:41 by areheman          #+#    #+#             */
/*   Updated: 2022/04/07 10:54:51 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save(char **s, int fd)
{
	char	*sv;
	int		i;
	int		j;

	i = 0;
	while (s[fd][i] && s[fd][i] != '\n')
		i++;
	if (!s[fd][i])
	{
		free(s[fd]);
		return (0);
	}
	sv = (char *)malloc(sizeof(char) * (ft_strlen(s[fd]) - i + 1));
	if (!sv)
		return (0);
	j = 0;
	while (s[fd][++i])
		sv[j++] = s[fd][i];
	sv[j] = '\0';
	free(s[fd]);
	return (sv);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char **sv)
{
	char	*buf;
	int		rd;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	rd = 1;
	while (!ft_strchr(sv, fd, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (0);
		}
		buf[rd] = '\0';
		sv[fd] = ft_strjoin(sv, buf, fd);
	}
	free(buf);
	return (sv[fd]);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sv[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (0);
	sv[fd] = ft_read_save(fd, sv);
	if (!sv[fd])
		return (0);
	line = ft_get_line(sv[fd]);
	sv[fd] = ft_save(sv, fd);
	return (line);
}

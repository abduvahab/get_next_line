/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:03:21 by areheman          #+#    #+#             */
/*   Updated: 2022/04/07 10:50:30 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char **s, int fd, int c)
{
	int	i;

	if (!s[fd])
		return (0);
	i = 0;
	while (s[fd][i] && s[fd][i] != (char)c)
		i++;
	if (s[fd][i] == (char)c)
		return (s[fd] + i);
	return (0);
}

char	*ft_strjoin(char **s1, char *s2, int fd)
{
	int		i;
	int		j;
	char	*s;

	if (!s1[fd])
	{
		s1[fd] = (char *)malloc(sizeof(char) * 1);
		*s1[fd] = '\0';
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1[fd]) + ft_strlen(s2) + 1));
	if (!s)
		return (0);
	i = -1;
	while (s1[fd][++i])
		s[i] = s1[fd][i];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1[fd]);
	return (s);
}

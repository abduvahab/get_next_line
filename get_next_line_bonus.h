/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:02:57 by areheman          #+#    #+#             */
/*   Updated: 2022/04/07 10:50:35 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_save(int fd, char **sv);
char	*ft_strchr(char **s, int fd, int c);
char	*ft_strjoin(char **s1, char *s2, int fd);
char	*ft_get_line(char *s);
char	*ft_save(char **s, int fd);
size_t	ft_strlen(char *s);

#endif

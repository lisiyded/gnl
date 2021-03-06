/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:29:28 by spowers           #+#    #+#             */
/*   Updated: 2020/07/10 14:17:00 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*check_ost(char *ost, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (ost)
		if ((p_n = ft_strchr(ost, '\n')))
		{
			*p_n = '\n';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n);
		}
		else
		{
			*line = ft_strdup(ost);
			if (*ost)
				while (*ost)
				{
					*ost = '\0';
					ost++;
				}
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*p_n;
	char		*tmp;
	static char	*ost;
	int			bytes;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(*line = ft_strdup(buf)))
		return (-1);
	p_n = check_ost(ost, line);
	while (!p_n && (bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			ost = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (bytes || ft_strlen(ost) || ft_strlen(*line)) ? 1 : 0;
}

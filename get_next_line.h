/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:37:41 by spowers           #+#    #+#             */
/*   Updated: 2020/07/06 17:08:39 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h> // open
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

int			get_next_line(int fd, char **line);
size_t		*ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *s, int c);
char            *ft_strdup(const char *s1);

#endif

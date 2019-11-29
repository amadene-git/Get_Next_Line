/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:48:28 by admadene          #+#    #+#             */
/*   Updated: 2019/11/08 15:08:38 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_chr(const char *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_sub(char const *s, unsigned int start, size_t len);
int		get_current_line(int fd, char **save);
int		get_next_line(int fd, char **line);

#endif

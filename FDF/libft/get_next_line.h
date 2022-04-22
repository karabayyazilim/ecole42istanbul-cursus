/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:16:38 by akarabay          #+#    #+#             */
/*   Updated: 2022/04/02 23:07:26 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 52
# endif

char	*get_next_line(int fd);
char	*ft_read_and_create(int fd, char *create);
char	*ft_create(char *create);

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *str, int c);
size_t	ft_strlcpy_gnl(char	*dst, const char *src, size_t	dstsize);
void	*ft_free(void *str);

#endif

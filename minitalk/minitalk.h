/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:00:47 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/23 16:06:19 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char	*str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc_exit(size_t count, size_t size);
void	ft_bzero(void *str, size_t number);
int		ft_recursive_power(int nb, int power);
void	ft_putendl(char *s);

#endif

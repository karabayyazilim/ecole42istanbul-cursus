/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:17 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/02 14:14:04 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

void	ft_putstr(char *str, int *res_val);
void	ft_putchar(char str, int *res_val);
void	ft_putnbr(int nb, int *res_val);
char	*ft_convert_base(size_t number, char *base_str);
void	ft_p_str(unsigned long number, int *res_val);
void	ft_put_u(unsigned int number, int *res_val);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);

#endif

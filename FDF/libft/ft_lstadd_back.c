/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:40:50 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 15:10:24 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*res;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	res = ft_lstlast(*lst);
	res->next = new;
}

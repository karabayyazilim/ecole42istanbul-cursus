/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:42:31 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 17:45:46 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*res;

	if (!del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		res = *lst;
		*lst = res->next;
		free(res);
	}
}

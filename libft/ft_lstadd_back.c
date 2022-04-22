/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:40:50 by akarabay          #+#    #+#             */
/*   Updated: 2022/02/02 12:48:49 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

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

//int main()
//{
//	t_list *lst = ft_lstnew("kjjgkug");
//	t_list *new = ft_lstnew("acsaca");
//	ft_lstadd_back(&lst, new);
	
//	ft_printf("%s", lst->next->content);
//}

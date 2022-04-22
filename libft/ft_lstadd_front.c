/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:54 by akarabay          #+#    #+#             */
/*   Updated: 2022/01/12 15:10:39 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*int main()
{
    t_list *lst = ft_lstnew(ft_strdup("asca"));
    t_list *new = ft_lstnew(ft_strdup("ali"));
    ft_lstadd_front(&lst, new);
    ft_printf("%s", lst->content);
}*/

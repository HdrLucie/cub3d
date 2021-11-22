/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:55:42 by luciehdr          #+#    #+#             */
/*   Updated: 2021/06/16 15:28:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = NULL;
	if (del)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp = *lst;
			(*lst) = (*lst)->next;
			free((tmp));
		}
	}
	else
		return ;
	*lst = NULL;
}

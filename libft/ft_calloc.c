/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:54:33 by luciehdr          #+#    #+#             */
/*   Updated: 2021/06/16 15:22:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = NULL;
	tab = malloc(nmemb * size);
	if (!(tab))
		return (NULL);
	ft_memset(tab, 0, (size * nmemb));
	return (tab);
}

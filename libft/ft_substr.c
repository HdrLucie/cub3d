/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:58:34 by luciehdr          #+#    #+#             */
/*   Updated: 2021/06/16 15:49:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	size;
	size_t	size_total;

	if (!s)
		return (NULL);
	copy = NULL;
	i = 0;
	size = ft_strlen(s);
	size_total = ft_int_ternaire(len >= size - start, size - start, len);
	copy = malloc(sizeof(char) * (size_total + 1));
	if (!(copy))
		return (NULL);
	while (s[start + i] && i < len && size > start)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:58:02 by luciehdr          #+#    #+#             */
/*   Updated: 2021/06/16 15:38:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2)) + 1));
	if (!(dest))
		return (NULL);
	while (s1[j] != '\0')
	{
		dest[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}

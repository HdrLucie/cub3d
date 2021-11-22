/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:32:20 by luciehdr          #+#    #+#             */
/*   Updated: 2021/06/23 19:06:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_double_tab(char **tab, int number_tab)
{
	while (number_tab >= 0)
	{
		free(tab[number_tab]);
		tab[number_tab] = NULL;
		number_tab--;
	}
	free(tab);
	tab = NULL;
}

static int	ft_counter_words(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	**ft_len_words(char **tab, char const *s, char c, int i)
{
	int		j;
	int		size;

	j = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i++] != c)
				size++;
			tab[j++] = malloc(sizeof(char) * (size + 1));
			if (!(tab))
			{
				ft_free_double_tab(tab, j);
				return (NULL);
			}
			size = 0;
		}
	}
	tab[j] = NULL;
	return (tab);
}

static char	**ft_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				tab[k][j] = s[i];
				i++;
				j++;
			}
			tab[k][j] = '\0';
			k++;
			j = 0;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * ft_counter_words(s, c) + 1);
	if (!(tab))
		return (NULL);
	ft_len_words(tab, s, c, i);
	ft_fill_tab(tab, s, c);
	return (tab);
}

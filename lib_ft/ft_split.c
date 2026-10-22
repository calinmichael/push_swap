/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:56:50 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/08 14:54:17 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
			{
				j++;
			}
			count++;
			if (!s[j])
			{
				break ;
			}
			i = j;
		}
		i++;
	}
	return (count);
}

char	*new_s(const char *s, size_t start, size_t j)
{
	char	*new;

	new = ft_substr(s, start, (j - start));
	if (!new)
	{
		return (0);
	}
	return (new);
}

int	find_j(const char *s, char c, size_t i)
{
	size_t	j;

	j = i;
	while (s[j] && s[j] != c)
	{
		j++;
	}
	return (j);
}

char	**allocate(const char *s, char c, char **array, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			j = find_j(s, c, i);
			array[idx] = new_s(s, start, j);
			idx++;
			if (!s[j])
			{
				break ;
			}
			i = j;
		}
		i++;
	}
	array[idx] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**array;
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	count = count_words(s, c);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
	{
		return (0);
	}
	return (allocate(s, c, array, start));
}

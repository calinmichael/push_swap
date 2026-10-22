/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 09:20:38 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/08 15:10:26 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	appear(char s1_i, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1_i == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	end(const char *s1, const char *set, size_t len_s1)
{
	size_t	i;

	i = 0;
	if (len_s1 > 0)
	{
		i = len_s1 - 1;
		while (i >= 1)
		{
			if (!appear(s1[i], set))
			{
				break ;
			}
			i--;
		}
		if (i == 0)
		{
			if (!appear(s1[0], set))
			{
				return (0);
			}
		}
	}
	return (i);
}

char	*result(const char *s1, size_t len_new_s, size_t left_bound)
{
	size_t	i;
	char	*new_s;

	i = 0;
	new_s = malloc(len_new_s + 1);
	if (!new_s)
	{
		return (0);
	}
	while (i < len_new_s)
	{
		new_s[i] = s1[left_bound + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_new_s;
	size_t	left_bound;
	size_t	right_bound;

	i = 0;
	len_new_s = 0;
	while (s1[i])
	{
		if (!appear(s1[i], set))
		{
			break ;
		}
		i++;
	}
	left_bound = i;
	len_s1 = ft_strlen(s1);
	if (left_bound == len_s1)
	{
		return (ft_strdup(""));
	}
	right_bound = end(s1, set, len_s1);
	len_new_s = right_bound - left_bound + 1;
	return (result(s1, len_new_s, left_bound));
}

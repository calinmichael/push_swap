/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 09:53:35 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/01 10:03:28 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	size_t	i;
	char	*str_dup;

	len_s = ft_strlen(s);
	str_dup = malloc(len_s + 1);
	if (!str_dup)
	{
		return (0);
	}
	i = 0;
	while (i < len_s)
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

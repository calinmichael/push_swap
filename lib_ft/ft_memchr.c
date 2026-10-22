/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:07:07 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/07 12:20:40 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t			i;
	const char		*s;
	unsigned char	c;

	i = 0;
	c = ch;
	s = ptr;
	if (count == 0)
	{
		return (NULL);
	}
	while (i < count)
	{
		if (s[i] == c)
		{
			return ((void *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

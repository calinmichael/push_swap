/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:46:15 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/07 13:11:41 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*p1;
	char		*p2;

	i = 0;
	p1 = src;
	p2 = dest;
	if (n == 0)
	{
		return (dest);
	}
	if (dest < src)
	{
		return (ft_memcpy(dest, src, n));
	}
	i = n - 1;
	while (i > 0)
	{
		p2[i] = p1[i];
		i--;
	}
	p2[i] = p1[i];
	return (dest);
}

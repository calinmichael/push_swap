/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 09:31:47 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/09 09:55:38 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	if (size != 0 && num > (i - 1) / size)
	{
		return (0);
	}
	str = malloc(num * size);
	if (!str)
	{
		return (0);
	}
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:23:55 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/06 14:34:39 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int value, size_t num)
{
	size_t	i;
	char	*ptr;

	ptr = str;
	i = 0;
	while (i < num)
	{
		ptr[i] = value;
		i++;
	}
	return (str);
}

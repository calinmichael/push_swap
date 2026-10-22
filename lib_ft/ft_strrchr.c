/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:35:45 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/07 11:56:32 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t			i;
	unsigned char	c;
	char			*found;

	i = 0;
	c = ch;
	found = NULL;
	while (str[i])
	{
		if (str[i] == c)
		{
			found = (char *)&str[i];
		}
		i++;
	}
	if (str[i] == c)
	{
		return ((char *)&str[i]);
	}
	return (found);
}

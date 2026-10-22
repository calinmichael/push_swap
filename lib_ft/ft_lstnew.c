/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:14:55 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 16:06:11 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int conv)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		return (0);
	}
	new->c = conv;
	new->next = NULL;
	return (new);
}

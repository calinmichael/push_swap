/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:11:46 by maratana          #+#    #+#             */
/*   Updated: 2026/11/04 17:45:22 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_list	*lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
}

int	lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

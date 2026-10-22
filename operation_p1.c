/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:02:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 15:41:24 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa & sb ccascava
void	swap(t_list **lst, char c)
{
	t_list	*head;
	t_list	*to_swap;
	int		count;

	if (*lst == NULL)
		return ;
	count = ft_lstsize(*lst);
	if (count == 1)
		return ;
	else
	{
		head = *lst;
		to_swap = (*lst)->next;
		to_swap->next = head;
		head->next = to_swap;
	}
	if (c == 'a')
		ft_printf("%s", "sa");
	else if (c == 'b')
		ft_printf("%s", "sb");
}
//ss ccascava
/*void	swap_both(t_list **lst_a, t_list **lst_b)
{
	
}
//pa & pb ccascava
void	push(t_list **lst_a, t_list **lst_b, char c)
{
	
}*/

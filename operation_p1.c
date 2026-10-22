/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:02:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 16:49:25 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa & sb ccascava
void	swap(t_list **lst, char c)
{
	t_list	*head;
	t_list	*to_swap;
	t_list	*remember;
	int		count;

	if (*lst == NULL)
		return ;
	count = ft_lstsize(*lst);
	if (count == 1)
		return ;
	else if (count > 2)
	{
		head = *lst;
		to_swap = (*lst)->next;
		remember = to_swap->next;
		head->next = remember;
		to_swap->next = head;
		*lst = to_swap;
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

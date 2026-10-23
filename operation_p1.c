/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:02:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/23 12:00:54 by ccascava         ###   ########.fr       */
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
	else
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

void	swap_both(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a, 'a');
	swap(lst_b, 'b');
}
//pa & pb ccascava

void	push_a(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (!(*lst_b))
		return ;
	head_b = *lst_b;
	temp = head_b->next;
	head_a = *lst_a;
	head_b->next = head_a;
	*lst_a = head_b;
	*lst_b = temp;
	if (c)
		ft_printf("%s", "pa");
}

void	push_b(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (!(*lst_a))
		return ;
	head_b = *lst_b;
	head_a = *lst_a;
	temp = head_a->next;
	head_a->next = head_b;
	*lst_b = head_a;
	*lst_a = temp;
	if (c)
		ft_printf("%s", "pb");
}

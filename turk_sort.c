/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:51:49 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/11 16:05:25 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	assign_rank(t_list **a, int *heap, int size)
{
	t_list	*temp;
	int		i;

	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (heap[i] == *(int *)temp->content)
			{
				temp->rank = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

int	*fill_array(t_list **a, int size)
{
	t_list	*temp;
	int		*heap;
	int		i;

	heap = malloc(size * sizeof(int));
	if (!heap)
		return (0);
	temp = *a;
	i = 0;
	while (temp && i < size)
	{
		heap[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	return (heap);
}

int	*bubble(t_list **a, int size)
{
	int		*heap;
	int		temporary;
	int		i;
	int		j;

	heap = fill_array(a, size);
	if (!heap)
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (heap[j] > heap[j + 1])
			{
				temporary = heap[j];
				heap[j] = heap[j + 1];
				heap[j + 1] = temporary;
			}
			j++;
		}
		i++;
	}
	assign_rank(a, heap, size);
	return (heap);
}

int	get_position(t_list **lst, t_list *target)
{
	int		position;
	t_list	*temp;

	temp = *lst;
	position = 0;
	while (temp)
	{
		if (temp == target)
		{
			return (position);
		}
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	manage_three(t_list **a, int largest_index)
{
	t_list	*temp;
	if (largest_index == 0)
		rotate(a, 'a');
	else if (largest_index == 1)
		rev_rotate(a, 'a');
	temp = *a;
	if (temp->rank != 0)
		swap(a, 'a');
}

void	sort_three_in_a(t_list **a)
{
	t_list	*temp;
	int		index;
	int		largest_rank;
	int		largest_index;

	temp = *a;
	largest_rank = temp->rank;
	largest_index = 0;
	temp = temp->next;
	index = 1;
	while (temp)
	{
		if (temp->rank > largest_rank)
		{
			largest_index = index;
			largest_rank = temp->rank;
		}
		index++;
		temp = temp->next;
	}
	if (!is_sorted(a))
		manage_three(a, largest_index);
}

void	assign_target(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*smallest;
	t_list	*target;
	int		smallest_rank;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		smallest = *a;
		smallest_rank = (*a)->rank;
		target = NULL;
		while (temp_a)
		{
			if (temp_a->rank < smallest_rank)
			{
				smallest_rank = temp_a->rank;
				smallest = temp_a;
			}
			if (temp_b->rank < temp_a->rank && (target == NULL || temp_a->rank < target->rank))
				target = temp_a;
			temp_a = temp_a->next;
		}
		if (target)
			temp_b->target = target;
		else
			temp_b->target = smallest;
		temp_b = temp_b->next;
	}
}

void	find_cost(t_list **a, t_list **b)
{
	int		pos_target;
	int		pos_b;
	int		cost_target;
	int		cost_b;
	t_list	*temp_b;
	
	temp_b = *b;
	while (temp_b)
	{
		pos_target = get_position(a, temp_b->target);
		pos_b = get_position(b, temp_b);
		if (pos_target <= lstsize(*a) / 2)
			cost_target = pos_target;
		else
			cost_target = lstsize(*a) - pos_target;
		if (pos_b <= lstsize(*b) / 2)
			cost_b = pos_b;
		else
			cost_b = lstsize(*b) - pos_b;
		temp_b->cost = cost_target + cost_b;
		temp_b = temp_b->next;
	}
}

t_list	*find_cheapest(t_list **b)
{
	t_list	*cheapest;
	t_list	*temp_b;

	temp_b = *b;
	cheapest = *b;
	while (temp_b)
	{
		if (temp_b->cost < cheapest->cost)
			cheapest = temp_b;
		temp_b = temp_b->next;
	}
	return (cheapest);
}

void	move_cheapest(t_list **a, t_list **b, t_list *cheapest)
{
	int	pos_cheapest;
	int	pos_target;

	pos_cheapest = get_position(b, cheapest);
	pos_target = get_position(a, cheapest->target);

	while (cheapest != *b)
	{
		if (pos_cheapest <= lstsize(*b) / 2)
			rotate(b, 'b');
		else
			rev_rotate(b, 'b');
	}
	while (cheapest->target != *a)
	{
		if (pos_target <= lstsize(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}

t_list	*get_smallest(t_list **a)
{
	t_list	*temp;
	t_list	*smallest;
	int		smallest_rank;

	temp = *a;
	smallest = *a;
	smallest_rank = (*a)->rank;
	while (temp)
	{
		if (temp->rank < smallest_rank)
		{
			smallest = temp;
			smallest_rank = temp->rank;
		}
		temp = temp->next;
	}
	return (smallest);
}

void	move_smallest(t_list **a, t_list *smallest)
{
	int		position;
	t_list	*temp;

	temp = *a;
	position = 0;
	while (temp)
	{
		if (temp == smallest)
			break ;
		position++;
		temp = temp->next;
	}
	while (smallest != *a)
	{
		if (position <= lstsize(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}

void	complex_sort(t_list **a, t_list **b, int size)
{
	int		*heap;
	t_list	*temp;
	t_list	*cheapest;
	t_list	*smallest;

	heap = bubble(a, size);
	if (heap == NULL)
		return ;
	while (lstsize(*a) > 3)
		push_b(a, b);
	sort_three_in_a(a);
	while (*b)
	{
		assign_target(a, b);
		find_cost(a, b);
		cheapest = find_cheapest(b);
		move_cheapest(a, b, cheapest);
		push_a(a, b);
	}
	smallest = get_smallest(a);
	move_smallest(a, smallest);
	temp = *a;
	while (temp)
	{
		ft_printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}


}

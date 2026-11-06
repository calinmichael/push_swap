/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:20:31 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/03 16:23:34 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	heapify(int	*heap, int parent, int size)
{
	int	left_child;
	int	right_child;
	int	temp;
	int	largest;

	largest = parent;
	left_child = 2 * parent + 1;
	right_child = 2 * parent + 2;
	if (left_child < size)
	{
		if (heap[parent] < heap[left_child])
		{
			largest = left_child;
		}
	}
	if (right_child < size)
	{
		if (heap[largest] < heap[right_child])
		{
			largest = right_child;
		}
	}
	if (largest != parent)
	{
		temp = heap[parent];
		heap[parent] = heap[largest];
		heap[largest] = temp;
		heapify(heap, largest, size);
	}
}

int	binary_search(int *heap, int find, int size)
{
	int	mid;
	int	right;
	int	left;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (heap[mid] < find)
			left = mid + 1;
		else if (heap[mid] > find)
			right = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

void	assign_rank(t_list **a, int *heap, int size)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		temp->rank = binary_search(heap, *(int *)temp->content, size);
		temp = temp->next;
	}
}

int	*heap_sort(t_list **a, int size)
{
	t_list	*temp;
	int		holder;
	int		*heap;
	int		parent;
	int		i;
	int		original_size;

	i = 0;
	original_size = size;
	heap = malloc(sizeof(int) * size);
	if (!heap)
		return (NULL);
	temp = *a;
	while (temp && i < size)
	{
		heap[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	parent = (size / 2) - 1;
	while (parent >= 0)
	{
		heapify(heap, parent, size);
		parent--;
	}
	while (size > 1)
	{
		holder = heap[0];
		heap[0] = heap[size - 1];
		heap[size - 1] = holder;
		size--;
		heapify(heap, 0, size);
	}
	assign_rank(a, heap, original_size);
	return (heap);
}

void	stack_operation(t_list **a, int size)
{
	int		*heap;
	t_list	*temp;
	
	heap = heap_sort(a, size);
	temp = *a;
	while (temp)
	{
		ft_printf("%d ", temp->rank);
		temp = temp->next;
	}
}

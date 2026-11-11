/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/11 15:45:42 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "utils.h"
#include "push_swap.h"
#include "validate.h"
#include <stdio.h>

//inits stack a by maratana
t_list	*init_a(char **argv)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*num;

	i = 1;
	while (argv[i] && is_flag(argv[i]))
		i++;
	if (!argv[i])
		return (NULL);
	num = malloc(sizeof(4));
	*num = myatoi(argv[i++]);
	ret = lstnew(num);
	while (argv[i])
	{
		if (is_flag(argv[i++]))
			continue ;
		num = malloc(4);
		*num = myatoi(argv[i - 1]);
		new = lstnew(num);
		lstadd_back(&ret, new);
	}
	return (ret);
}
int	get_list_val(int lst_i, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && lst_i != i)
	{
		lst = lst->next;
		i++;
	}
	return (*(int *)lst->content);
}

double	compute_disorder(t_list *a)
{
	double			mistakes;
	double			pairs;
	unsigned int	i;
	unsigned int				j;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < lstsize(a))
	{
		j = i + 1;
		while (j < lstsize(a))
		{
			pairs += 1;
			if (get_list_val(i, a) > get_list_val(j, a))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / pairs);
}

void	print_list(t_list *lst_a, t_list *lst_b)
{
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_printf("%d ", *(int *)lst_a->content);
			lst_a = lst_a->next;
		}
		if (lst_b)
		{
			ft_printf("%d", *(int *)lst_b->content);
			lst_b = lst_b->next;
		}
		printf("\n");
	}
	ft_printf("_ _\n");
	ft_printf("%c %c\n", 'a', 'b');
}

int	is_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
void	bubble_sort(t_list **a, t_list **b)
{
	t_list	*temp;

	while (is_sorted(a) == 0)
	{
		while (*a)
		{
			if ((*a)->next)
			{
				temp = (*a)->next;
				if (*(int *)(*a)->content > *(int *)temp->content)
					swap(a, 'a');
			}
			push_b(a, b);
		}
		while (*b)
		{
			if ((*b)->next)
			{
				temp = (*b)->next;
				if (*(int *)(*b)->content < *(int *)temp->content)
					swap(b, 'b');
			}
			push_a(a, b);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	//---- VALDATION -----
	if (argc <= 1)
		return (0);
	if (!validate_input(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	//---- END VALDATION -----
	a = init_a(argv);
	b = NULL;
	printf("%f\n", compute_disorder(a));
	
	complex_sort(&a, &b, lstsize(a));
	// ft_printf("%d", *(int *)a->content);
	//print_list(a, b);
	//bubble_sort(&a, &b);
	//print_list(a, b);
}

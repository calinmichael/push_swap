/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 18:07:40 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

//checks for non ints;
int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
					|| (argv[i][j] == '-')))
			{
				write(1, &argv[i][j], 1);
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// checks duplicates in the list by maratana
int	lstcheck_dupe(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

//inits stack a by maratana
t_list	*init_a(int argc, char **argv)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*n;

	i = 1;
	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = ft_atoi(argv[i]);
	ret = ft_lstnew(n);
	i++;
	while (i < argc)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		new = ft_lstnew(n);
		ft_lstadd_back(&ret, new);
		i++;
	}
	return (ret);
}
// double	compute_disorder(t_list *a)
// {
// 	double	mistakes;
// 	double	pairs;
// 	int		i;
// 	int		j;

// 	mistakes = 0;
// 	pairs = 0;
// 	i = 0;
// 	while (i < ft_lstsize(a) - 1)
// 	{
// 		j = i + 1;
// 		while (j < ft_lstsize(a) - 1)
// 		{
// 			pairs += 1;
// 			if()
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (mistakes / pairs);
// }

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;

	// if (argc < 2)
	// {
	// 	ft_printf("Usage: ./push_swap <numbers...>\n");
	// 	return (1);
	// }
	if (!check_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	a = init_a(argc, argv);
	if (!a)
		return (1);
	ft_printf("Before swap:\n");
	print_list(a);
	printf("%i", lstcheck_dupe(a));
	//printf("%f\n",compute_disorder(a));
	/*
	ft_printf("After swap:\n");
	print_list(a);*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/24 13:55:31 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

char	*check_flag(char **argv, int *i)
{
	char	*flag;

	flag = "--adaptive";
	if (!ft_strncmp(argv[1], "--simple", 8) || !ft_strncmp(argv[1], "--medium", 8))
	{
		flag = argv[1];
		(*i)++;
	}
	else if (!ft_strncmp(argv[1], "--complex", 9) || !ft_strncmp(argv[1], "--adaptive", 10))
	{
		flag = argv[1];
		(*i)++;
	}
	return (flag);
}

//checks for non ints;
char *check_input(int argc, char **argv)
{
	int		i;
	size_t	j;
	size_t	arg_len;
	char	*flag;

	i = 1;
	flag = check_flag(argv, &i);
	while (i < argc)
	{
		j = 0;
		arg_len = ft_strlen(argv[i]);
		while (j < arg_len)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				if (arg_len >= 2 && !(argv[i][0] == '-'))
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (flag);
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
t_list	*init_a(int argc, char **argv, char *flag)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*n;

	if (argv[1] == flag)
		i = 2;
	else
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	a = init_a(argc, argv, check_input(argc, argv));
	if (lstcheck_dupe(a))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	b = NULL;
	print_list(a, b);
	push_b(&a, &b, 'b');
	print_list(a, b);
	//printf("%i", lstcheck_dupe(a));
	//printf("%f\n",compute_disorder(a));
	return (0);
}
